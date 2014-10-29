/*******************************
A*

The implementation of algorithm A*.
*******************************/

#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

#define SYM_WALL '#'
#define MAX_DIST 10000

struct Node
{
	int x;
	int y;
	int f;
	int g;
	int h;
	Node(){}
	Node(int x, int y){this->x = x, this->y = y;}
	Node(int x, int y, int g, int h){this->x = x, this->y = y, this->g = g, this->h = h, this->f = g + h;}
	bool operator < (const Node &right) const {return this->f <= right.f;}
};

class AStar
{
public:
	AStar(vector<vector<char> > &map);
	int search(int sx, int sy, int ex, int ey);

private:
	int distance(int sx, int sy, int ex, int ey);
	void check(int x, int y, int ex, int ey, Node &node, multiset<Node> &open, set<int> &close);
	inline int index(int x, int y) {return x*w + y;}
	inline int posX(int index) {return index / w;}
	inline int posY(int index) {return index % w;}
private:
	vector<vector<char> > map;
	int w;
	int h;
};

AStar::AStar(vector<vector<char> > &map)
{
	this->map = map;
	h = map.size();
	w = map[0].size();
}

int AStar::distance(int sx, int sy, int ex, int ey)
{
	return abs(sx-ex) + abs(sy-ey);
}

int AStar::search(int sx, int sy, int ex, int ey)
{
	multiset<Node> open;
	set<int> close;
	Node node(sx, sy, 0, distance(sx, sy, ex, ey));
	open.insert(node);

	while(!open.empty())
	{
		node = *open.begin();
		open.erase(open.begin());
		close.insert(index(node.x, node.y));

		if(node.x == ex && node.y == ey)
			return node.f;

		check(node.x, node.y-1, ex, ey, node, open, close);
		check(node.x, node.y+1, ex, ey, node, open, close);
		check(node.x-1, node.y, ex, ey, node, open, close);
		check(node.x+1, node.y, ex, ey, node, open, close);
	}

	return MAX_DIST;
}

void AStar::check(int x, int y, int ex, int ey, Node &parent, multiset<Node> &open, set<int> &close)
{
	if(x < 0 || x >= h || y < 0 || y >= w || close.end() != close.find(index(x, y)))
		return ;

	if(SYM_WALL == map[x][y])
	{
		close.insert(index(x, y));
		return ;
	}

	multiset<Node>::iterator iter = open.begin();
	while(iter != open.end() && (iter->x != x || iter->y != y)) iter++;

	if(open.end() == iter)
	{
		Node node(x, y, parent.g+1, distance(x, y, ex, ey));
		open.insert(node);
	} else {
		if(iter->g > parent.g + 1)
		{
			Node node = *iter;
			node.g = parent.g + 1;
			node.f = node.g + node.h;
			open.erase(iter);
			open.insert(node);
		}
	}
}

int main()
{
	ifstream in("astar_map.txt");
	int w, h;
	char ch;
	vector<vector<char> > map;

	in>>w>>h;
	for(int i = 0; i < h; i++)
	{
		vector<char> line;
		for(int j = 0; j < w; j++)
		{
			in>>ch;
			line.push_back(ch);
		}

		map.push_back(line);
	}

	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; j < map[i].size(); j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	AStar astar(map);
	int sx, sy, ex, ey;
	while(true)
	{
		cin>>sx>>sy>>ex>>ey;
		cout<<astar.search(sx, sy, ex, ey)<<endl;
	}

	return 0;
}

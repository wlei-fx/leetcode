/******************************************
Orienteering

We are planning an orienteering game.
The aim of this game is to arrive at the goal (G) from the start (S) with the shortest distance.
However, the players have to pass all the checkpoints (@) on the map.
An orienteering map is to be given in the following format.
########
#@....G#
##.##@##
#..@..S#
#@.....#
########
In this problem, an orienteering map is to be given.
Calculate the minimum distance from the start to the goal with passing all the checkpoints.

Specification:
A map consists of 5 characters as following. You can assume that the map does not contain any invalid characters and the map has exactly one start symbol 'S' and exactly one goal symbol 'G'.
  'S' means the orienteering start.
  'G' means the orienteering goal.
  '@' means an orienteering checkpoint.
  '.' means an opened-block that players can pass.
  '#' means a closed-block that players cannot pass.

It is allowed to move only by one step vertically or horizontally (up, down, left, or right) to the next block.
Other types of movements, such as moving diagonally (left up, right up, left down and right down) and skipping one or more blocks, are NOT permitted.
You MUST NOT get out of the map.
Distance is to be defined as the number of movements to the different blocks.
You CAN pass opened-blocks, checkpoints, the start, and the goal more than once if necessary.

You can assume that parameters satisfy following conditions.
1 <= width <= 100
1 <= height <= 100
The maximum number of checkpoints is 18.

Return -1 if given arguments do not satisfy specifications, or players cannot arrive at the goal
from the start by passing all the checkpoints.

Input:
The input is to be given in the following format, from the standard input.
W H
Row1
Row2
...
RowH
The first row is to describe the width and the height of the orienteering map, sectioned by a space.
From the second row, map information is to be given for exactly the same number of rows as the
height.
Each row contains exactly the same number of letters as the width.
See “Specification” for details of the symbols contained in the map.

Output:
Output into the standard output, and put a return.

Example1
<Input>
5 4
#####
#...#
#S#G#
#####
<Output>
4

Example2
<Input>
5 5
#####
#.@@#
#S###
#..G#
#####
<Output>
9

Example3
<Input>
5 5
#####
#S..#
##G##
#..@#
#####
<Output>
6
******************************************/

//#define MY_DEBUG
#undef MY_DEBUG
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

#ifdef MY_DEBUG
#include <fstream>
#endif

using namespace std;

#define MAX_WIDTH		100
#define MAX_HEIGHT		100
#define MAX_CHECKPOINTS	18
#define SYM_START		'S'
#define SYM_GOAL		'G'
#define SYM_CHECKPOINT	'@'
#define SYM_ROAD		'.'
#define SYM_WALL		'#'


// the upper bound of distance between 2 points
const int MAX_DIST = MAX_WIDTH * MAX_HEIGHT;

// data struct for A* algorithm
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

// implementation of A* algorithm
class AStar
{
public:
	// constructor
	AStar(vector<vector<char> > &map);

	// search the shortest path from (sx, sy) to (ex, ey) in map
	// return the length of the shortest path
	int search(int sx, int sy, int ex, int ey);

private:
	// calculate the Manhattan distance between (sx, sy) and (ex, ey)
	int distance(int sx, int sy, int ex, int ey);
	
	// a helper to A*
	void check(int x, int y, int ex, int ey, Node &node, multiset<Node> &open, set<int> &close);
	
	// convert 2-D coordinate to 1-D
	inline int index(int x, int y) {return x*w + y;}

	// convert 1-D coordinate to 2-D
	inline int posX(int index) {return index / w;}
	inline int posY(int index) {return index % w;}
private:
	vector<vector<char> > map;
	int w;							// width of map
	int h;							// height of map
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

struct Point
{
	int x;
	int y;
	Point(int x1, int y1): x(x1), y(y1){}
};

class AStar;

class Orienteering
{
public:
	void main();
private:
	// deal with input
	int input();

	// put the start, goal and checkpoints into an array
	// start point is put at the first place and goad at last
	void initPoints(int pts);
	void printDist();
private:
	vector<vector<char> > map;
	vector<Point> points;					// array of start point, checkpoints, goal point
	vector<vector<int> > dist;				// 2-D array of distance between 2 points
};

void Orienteering::main()
{
	// deal with input
	int pts = input();
	if(-1 == pts)
	{
		cout<<-1<<endl;
		return ;
	}

	// initialize points array
	initPoints(pts);

	// use A* to find the shortest path between each 2 points
	AStar astar(map);
	for(int i = 0; i < points.size(); i++)
	{
		for(int j = i+1; j < points.size(); j++)
		{
			int d = astar.search(points[i].x, points[i].y, points[j].x, points[j].y);
			if(MAX_DIST == d)
			{
				cout<<-1<<endl;
				return ;
			}
			dist[i][j] = dist[j][i] = d;
		}
	}
#ifdef MY_DEBUG
	printDist();
#endif

	vector<int> seq;			// sequence of the last route, 
									//the route contains only start and goal at first
	seq.push_back(0);
	seq.push_back(pts-1);

	set<int> added;				// a set of points that already added to 
	added.insert(0);
	added.insert(pts-1);

	// when not all points are added to seq
	while(added.size() < pts)
	{
		int min_cost = MAX_DIST, pos, pt;
		
		// for each point not added to seq
		for(int i = 1; i < pts-1; i++)
		{
			if(added.end() != added.find(i))
				continue ;

			// insert the point between each 2 adjacent points
			// and calculate the cost of inserting the point
			// find out the point and position which causes the minimum cost
			for(int j = 0; j < seq.size()-1; j++)
			{
				int cost = dist[seq[j]][i] + dist[i][seq[j+1]] - dist[seq[j]][seq[j+1]];
				if(cost < min_cost)
				{
					min_cost = cost;
					pos = j;
					pt = i;
				}
			}
		}
		
		// insert the minimum cost point at position in route
		seq.insert(seq.begin()+pos+1, pt);
		added.insert(pt);
	}

	// calculate the total cost
	int sum = 0;
	for(int i = 0; i < seq.size()-1; i++)
	{
		sum += dist[seq[i]][seq[i+1]];
	}
	cout<<sum<<endl;
}

int Orienteering::input()
{
#ifdef MY_DEBUG
	ifstream in("orienteering_example.txt");
#else
#define in cin
#endif

	int w, h, cp = 0, s = 0, g = 0;
	char ch;
	in>>w>>h;

	if(w >= MAX_WIDTH || h >= MAX_HEIGHT || w <= 0 || h <= 0)
		return -1;

	for(int i = 0; i < h; i++)
	{
		vector<char> line;
		for(int j = 0; j < w; j++)
		{
			in>>ch;
			if(SYM_CHECKPOINT == ch)
				cp++;
			else if(SYM_START == ch)
				s++;
			else if(SYM_GOAL == ch)
				g++;
			else if(SYM_ROAD != ch && SYM_WALL != ch)
				return -1;
			line.push_back(ch);
		}
		map.push_back(line);
	}
#ifdef MY_DEBUG
	cout<<"****************map****************"<<endl;
	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; j < map[i].size(); j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}
#endif
	if(cp <= MAX_CHECKPOINTS && 1 == s && 1 == g)
		return cp + 2;
	return -1;
}

void Orienteering::initPoints(int pts)
{
	points = vector<Point>(pts, Point(-1, -1));
	int insertPos = 1;
	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; j < map[i].size(); j++)
		{
			int curInsertPos;
			if(SYM_START == map[i][j])
				curInsertPos = 0;
			else if(SYM_GOAL == map[i][j])
				curInsertPos = pts - 1;
			else if(SYM_CHECKPOINT == map[i][j])
				curInsertPos = insertPos++;
			else
				continue ;
			points[curInsertPos].x = i;
			points[curInsertPos].y = j;
		}
	}

	dist = vector<vector<int> >(pts, vector<int>(pts, MAX_DIST));
#ifdef MY_DEBUG
	for(int i = 0; i < points.size(); i++)
		cout<<"("<<points[i].x<<","<<points[i].y<<")";
	cout<<endl;
	printDist();
#endif
}

void Orienteering::printDist()
{
	cout<<"****************dist***************"<<endl;
	for(int i = 0; i < dist.size(); i++)
	{
		for(int j = 0; j < dist[i].size(); j++)
		{
			cout<<dist[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(int argc, char* argv[])
{
	Orienteering o;
	o.main();
	return 0;
}

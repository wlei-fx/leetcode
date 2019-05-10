/***************************************
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
***************************************/

#include "tools.h"

class LRUCache
{
private:
	static const int INVALID_KEY = -1;
	struct value
	{
		value(){}
		value(int v, int p = INVALID_KEY, int n = INVALID_KEY) {val = v, prev = p, next = n;}
		int val;
		int prev;
		int next;
	};
	map<int, value> cache;
	int capacity, head, tail;
public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
		head = tail = INVALID_KEY;
	}
	
	void print() {
		cout<<endl<<"cache content: "<<endl;
		cout<<"head: "<<head<<"    tail: "<<tail<<endl;
		auto it = cache.find(head);
		while (it != cache.end()) {
			cout<<it->first<<": "<<it->second.prev<<"->"<<it->second.val<<"->"<<it->second.next<<endl;
			it = cache.find(it->second.next);
		}
		cout<<"----------------------------------\n\n";
	}

	int get(int key)
	{
		map<int, value>::iterator it = cache.find(key);
		if(it == cache.end())
		{
			return -1;
		}

		map<int, value>::iterator prev = cache.find(it->second.prev),
			next = cache.find(it->second.next);
		if(prev != cache.end() && next != cache.end()) {
			prev->second.next = it->second.next;
			next->second.prev = it->second.prev;
			it->second.prev = INVALID_KEY;
			it->second.next = head;
			cache.find(head)->second.prev = key;
			head = key;
		} else if(prev != cache.end() && next == cache.end()) {
			it->second.prev = INVALID_KEY;
			it->second.next = head;
			cache.find(head)->second.prev = key;
			head = key;
			prev->second.next = INVALID_KEY;
			tail = prev->first;
		}
		return it->second.val;
	}

	void put(int key, int val)
	{
		if(0 == capacity) return ;
		if(cache.find(key) != cache.end()) {
			map<int, value>::iterator it = cache.find(key),
				prev = cache.find(it->second.prev),
				next = cache.find(it->second.next);
			it->second.val = val;
			if(prev != cache.end() && next != cache.end()) {
				prev->second.next = it->second.next;
				next->second.prev = it->second.prev;
				it->second.prev = INVALID_KEY;
				it->second.next = head;
				cache.find(head)->second.prev = key;
				head = key;
			} else if(prev != cache.end() && next == cache.end()) {
				it->second.prev = INVALID_KEY;
				it->second.next = head;
				cache.find(head)->second.prev = key;
				head = key;
				prev->second.next = INVALID_KEY;
				tail = prev->first;
			}
		} else {
			if(cache.size() == capacity)
			{
				map<int, value>::iterator it = cache.find(tail),
					prev = cache.find(it->second.prev);
				if(prev != cache.end()) {
					prev->second.next = INVALID_KEY;
					tail = prev->first;
				} else {
					tail = INVALID_KEY;
				}
				cache.erase(it);
				head = tail == INVALID_KEY ? INVALID_KEY : head;
			}
			cache[key] = value(val, INVALID_KEY, head);
			if(INVALID_KEY != head)
				cache.find(head)->second.prev = key;
			head = key;
			tail = tail == INVALID_KEY ? head : tail;
		}
	}
};

int main()
{
	
	vector<string> op = {"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
	vector<vector<int>> oprands = {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
	
	LRUCache cache(oprands[0][0]);
	
	for(int i = 1; i < op.size(); i++) {
		if (op[i] == "put") {
			cout<<"put "<<oprands[i][0]<<" -> "<<oprands[i][1]<<endl;
			cache.put(oprands[i][0], oprands[i][1]);
			cache.print();
		} else {
			cout<<"get "<<oprands[i][0]<<" -> "<<cache.get(oprands[i][0])<<endl;
			cache.print();
			
		}
	}
	
	return 0;
}

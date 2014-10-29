/***************************************
LRU Cache 

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
***************************************/

#include "tools.h"

class LRUCache
{
private:
	struct value
	{
		value(){}
		value(int v, int p = INT_MIN, int n = INT_MIN) {val = v, prev = p, next = n;}
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
		head = tail = INT_MIN;
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
			it->second.prev = INT_MIN;
			it->second.next = head;
			cache.find(head)->second.prev = key;
			head = key;
		} else if(prev != cache.end() && next == cache.end()) {
			it->second.prev = INT_MIN;
			it->second.next = head;
			cache.find(head)->second.prev = key;
			head = key;
			prev->second.next = INT_MIN;
			tail = prev->second.val;
		}

		return it->second.val;
	}

	void set(int key, int val)
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
				it->second.prev = INT_MIN;
				it->second.next = head;
				cache.find(head)->second.prev = key;
				head = key;
			} else if(prev != cache.end() && next == cache.end()) {
				it->second.prev = INT_MIN;
				it->second.next = head;
				cache.find(head)->second.prev = key;
				head = key;
				prev->second.next = INT_MIN;
				tail = prev->second.val;
			}
		} else {
			if(cache.size() == capacity)
			{
				map<int, value>::iterator it = cache.find(tail),
					prev = cache.find(it->second.prev);
				tail = it->second.prev;
				if(prev != cache.end())
					prev->second.next = INT_MIN;
				cache.erase(it);
				head = tail == INT_MIN ? INT_MIN : head;
			}
			cache[key] = value(val, INT_MIN, head);
			if(INT_MIN != head)
				cache.find(head)->second.prev = key;
			head = key;
			tail = tail == INT_MIN ? head : tail;
		}
	}
};

int main()
{
	int capacity = 2;
	LRUCache cache(capacity);

	int op[] =  {0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0};
	int key[] = {1, 1, 2, 3, 4, 1, 2, 3, 4, 5, 1, 5, 1, 1, 5, 2};
	int val[] = {0, 1, 2, 3, 4, 0, 0, 0, 0, 5, 0, 0, 1, 0, 0, 0};
/*
	int op[]  = {1, 1, 0, 1, 0, 0};
	int key[] = {2, 1, 2, 4, 1, 2};
	int val[] = {1, 1, 0, 1, 0, 0};
*/
	for(int i = 0; i < sizeof(op)/sizeof(int); i++)
	{
		if(op[i] == 0)
		{
			cout<<key[i]<<"->"<<cache.get(key[i])<<endl;
		} else {
			cout<<"insert "<<key[i]<<"->"<<val[i]<<endl;
			cache.set(key[i], val[i]);
		}
	}
	return 0;
}

#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

template <class T>
void print(vector<T> &v)
{
	cout<<"[";
	for_each(v.begin(), v.end(), [](T t) {
		cout<<t<<",";		
	});
	cout<<"]"<<endl;
}

template <class T>
void print(vector<vector<T>> &v)
{
	for_each(v.begin(), v.end(), [](vector<T> &vec) {
		print(vec);
	});
}

#endif

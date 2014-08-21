#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
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


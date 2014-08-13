/*************************************************************************
       File: search_for_a_range.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-12 22:08:40

Search for a Range 

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
************************************************************************/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(int A[], int n, int target)
	{
		vector<int> result(2, -1);
		search(A, 0, n-1, target, result);

		return result;
	}

	// search target between m & n
	// when tag = 0, search lowest
	// when tag = 1, search highest
	int search(int A[], int m, int n, int target, int tag)
	{
		if(m > n)
		{
			return tag ? n : m;
		}

		int mid = (m+n)/2;
		if(target == A[mid])
		{
			return tag ? search(A, mid+1, n, target, tag) 
				: search(A, m, mid-1, target, tag);
		} else {
			return tag ? search(A, m, mid-1, target, tag)
				: search(A, mid+1, n, target, tag);
		}
	}

	void search(int A[], int m, int n, int target, vector<int> &result)
	{
		if(m > n)
		{
			result[0] = -1;
			result[1] = -1;
			return ;
		}
		int mid = (m+n)/2;
		if(target == A[mid])
		{
			result[0] = search(A, m, mid-1, target, 0);
			result[0] = -1 == result[0] ? mid : result[0];
			
			result[1] = search(A, mid+1, n, target, 1);
			result[1] = -1 == result[1] ? mid : result[1];
		} else if(target < A[mid]) {
			search(A, m, mid-1, target, result);
		} else {
			search(A, mid+1, n, target, result);
		}
	}
};

int main()
{
	int A[] = {5, 7, 7, 8, 8, 10, 11, 23, 23, 23, 23};
	vector<int> result = (new Solution())->searchRange(A, sizeof(A)/sizeof(0), 23);
	cout<<"["<<result[0]<<", "<<result[1]<<"]"<<endl;
}


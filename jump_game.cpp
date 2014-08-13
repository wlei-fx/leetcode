/*************************************************************************
       File: jump_game.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-12 22:08:36

Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
************************************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	bool canJump(int A[], int n)
	{
		if(1 == n) return A[0] >= 0;				// if only 1 element

		for(int i = 1; i < n && i <= A[i-1]; i++)	// mark each element the farest position it can go
		{
			if(i+A[i] >= n-1)						// reach last element
				return true;

			if(i+A[i] < A[i-1])						
				A[i] = A[i-1];
			else
				A[i] = i + A[i];
		}

		return false;
	}
};

int main()
{
	//int A[] = {2,3,1,1,4};
	//int A[] = {3,2,1,0,4};
	//int A[] = {1,1,1,1,1};
	int A[] = {3,0,0,0};
	cout<<(new Solution())->canJump(A, sizeof(A)/sizeof(0));
}

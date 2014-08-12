/*
Trapping Rain Water 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

                _
        _      | |_   _
   _   | |_   _| | |_| |_
__|_|__|_| |_|_|_|_|_|_|_|

*/

#include<iostream>
using namespace std;

class Solution
{
public:
	int trap(int A[], int n)
	{
		int i = 0, j = 1, sum = 0;

		// scan from left to right, find the first not lower than current bar
		while(i < n && j < n)
		{
			int total = 0, peak = i+1;
			while(j < n && A[j] < A[i])
			{
				peak = A[peak] < A[j] ? j : peak;
				total += A[i] - A[j++];
			}

			if(j < n)								// find bar j not lower than current bar i
			{
				sum += total;						// then add capacity between i and j
				i = j;
				j = i + 1;
			} else {
				for(int k = i+1; k < peak; k++)    // peak is the maximum after i, then add capacity between i and peak
				{
					sum += A[peak] - A[k];
				}

				i = peak;
				j = i + 1;
			}
		}

		return sum;
	}
};

int main()
{
	int A[] = {4,2,0,3,2,5};
	int n = sizeof(A) / sizeof(0);
	
	cout<<(new Solution())->trap(A, n);
}

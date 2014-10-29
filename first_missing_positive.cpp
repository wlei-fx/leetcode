/*******************************
First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*******************************/

#include "tools.h"

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for(int i = 0; i < n; )
		{
			if(A[i] > 0 && A[i] <= n && i+1 != A[i] && A[i] != A[A[i]-1])
			{
				int tmp = A[i];
				A[i] = A[tmp-1];
				A[tmp-1] = tmp;
			} else {
				i++;
			}
		}

		int last = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] != i+1)
				return i+1;
			else
				last = i+1;
		}

		return last + 1;
	}
};

int main()
{
	int A[] = {};
	//int A[] = {1};
	//int A[] = {1,1};
	//int A[] = {2,1};
	cout<<(new Solution())->firstMissingPositive(A, sizeof(A)/sizeof(int))<<endl;
}

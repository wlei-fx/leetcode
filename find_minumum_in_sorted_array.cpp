/************************************
Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.

You may assume no duplicate exists in the array.
************************************/

#include "tools.h"

class Solution {
public:
	int findMin(vector<int> &num)
	{
		return findMin(num, 0, num.size()-1);
	}

	int findMin(vector<int> &num, int start, int end)
	{
		if(start == end)
		{
			return num[start];
		}

		int mid = (start + end) / 2;
		if(num[start] <= num[mid] && num[mid] < num[end])
		{
			return num[start];
		}

		if(num[start] <= num[mid] && num[mid] > num[end])
		{
			return findMin(num, mid+1, end);
		}

		if(num[start] >= num[mid] && num[mid] < num[end])
		{
			return findMin(num, start, mid);
		}

		return num[end];
	}
};

int main()
{
	int A[] = {3,2,1,0};
	vector<int> num(A, A+sizeof(A)/sizeof(int));

	cout<<(new Solution())->findMin(num)<<endl;
	return 0;
}

/************************************************
Find Minimum in Rotated Sorted Array II 

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.

The array may contain duplicates.
************************************************/

#include "tools.h"

class Solution
{
public:
	int findMin(vector<int> &num)
	{
		return findMin(num, 0, num.size()-1);
	}

	int findMin(vector<int> &num, int start, int end)
	{
		if(start == end)
			return num[start];

		int mid = (start + end) / 2;
		if(num[start] <= num[mid] && num[mid] <= num[end])
		{
			int left = findMin(num, start, mid);
			int right = findMin(num, mid+1, end);
			return min(left, right);
		} else if(num[start] <= num[mid] && num[mid] > num[end]) {
			return findMin(num, mid+1, end);
		} else if(num[start] > num[mid] && num[mid] >= num[end]) {
			int left = findMin(num, start, mid);
			int right = findMin(num, mid+1, end);
			return min(left, right);
		} else {
			return findMin(num, start+1, mid);
		}
	}
};

int main()
{
	//int A[] = {4,4,4,5,6,7,0,1,2};
	//int A[] = {0};
	//int A[] = {0,1,1,2,2,3,3,4,4};
	//int A[] = {7,7,8,8,9,1,2,2,2,3,4};
	//int A[] = {3,3,1,3};
	int A[] = {2,0,1,1,1};
	vector<int> num(A, A+sizeof(A)/sizeof(int));

	cout<<(new Solution())->findMin(num)<<endl;
	return 0;
}

/*********************************************
Median of Two Sorted Arrays 

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*********************************************/

#include "tools.h"

class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		return findMedianSortedArrays(A, 0, m-1, B, 0, n-1, (m+n)/2, (m+n)%2);
	}

	double findMedianSortedArrays(int A[], int s, int t, int B[], int p, int q, int k, bool single)
	{

	}
};

int main()
{
	int A[] = {1,2,3};
	int B[] = {4,5};

	cout<<(new Solution())->findMedianSortedArrays(
				A, sizeof(A)/sizeof(int), 
				B, sizeof(B)/sizeof(int))
		<<endl;

	return 0;
}

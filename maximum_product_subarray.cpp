/******************************************
Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
******************************************/

#include "tools.h"

class Solution
{
public:
	int maxProduct(int A[], int n)
	{
		int max_local = A[0], min_local = A[0], max_global = A[0];

		for(int i = 1; i < n; i++)
		{
			int tmp = max_local;
			max_local = max(max(tmp*A[i], A[i]), min_local*A[i]);
			min_local = min(min(tmp*A[i], A[i]), min_local*A[i]);
			max_global = max(max_local, max_global);
		}

		return max_global;
	}
};

int main()
{
	int A[] = {3,2,-2,-2,-100};
	cout<<(new Solution())->maxProduct(A, sizeof(A)/sizeof(int))<<endl;
	return 0;
}

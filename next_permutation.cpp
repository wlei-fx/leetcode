/*************************************************************************
       File: next_permutation.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-23 20:50:05

Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
************************************************************************/

#include "tools.h"

class Solution
{
public:
	void nextPermutation(vector<int> &num)
	{
		int i = num.size() - 1;
		for(; i > 0 && num[i] <= num[i-1]; i--) ;	// 找到i比i-1处大的最大的i 

		if(0 == i)	// num非升序，按升序排序
		{
			sort(num.begin(), num.end());
			return ;
		}

		int m = num.size() - 1;
		for(; m >= i && num[m] <= num[i-1]; m--) ;	// 找到i后面比i-1大的最小的数，注意i~n-1是有序的

		swap(num[m], num[i-1]);						// 交换m和i-1处的值
		for(int p = i, q = num.size()-1; p < q; p++, q--)		// 将i~n-1间的值重新按非降序排序
			swap(num[p], num[q]);

	}
};

int main()
{
	int A[] = {1,1,5};
	vector<int> num(A, A+sizeof(A)/sizeof(0));
	print(num);
	(new Solution())->nextPermutation(num);

	print(num);
}


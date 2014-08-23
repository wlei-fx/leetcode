/*************************************************************************
       File: jump_game_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-23 17:19:24

Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
************************************************************************/

#include "tools.h"
#define INT_MAX 0x7fffffff
class Solution
{
public:
	int jump(int A[], int n)
	{
		int *steps = new int[n];
		steps[n-1] = 0;					// 最后一格到自己最少要０步

		for(int i = n-2; i >= 0; i--)
		{
			steps[i] = INT_MAX;		// 初始化每一格到最后一格的最小步数为INT_MAX
			for(int j = i+1; j <= i+A[i] && j < n; j++)
			{
				// 每一格的最小步数为它所能到达的格子的最小步数加1
				steps[i] = steps[i] > (1+steps[j]) ? (1+steps[j]) : steps[i];
			}
			
		}

		return steps[0];
	}

	// 优化版本
	int jump_optimized(int A[], int n)
	{
		int *dest = new int[n];
		for(int i = 0; i < n; i++)
		{
			dest[i] = i + A[i];			// 每一个格子所能到达的最大距离
		}

		int target = n - 1, steps = 0;
		for(int i = 0; i < n; )
		{
			if(0 == target)
				break;
			if(dest[i] >= target)		// 依次寻找能够到达目标的最小格子
			{
				target = i;
				i = 0;
				steps++;
			} else {
				i++;
			}
		}

		return steps;
	}
};

int main()
{
	int A[] = {2,3,1,1,4,1,1,1,4};
	cout<<(new Solution())->jump_optimized(A, sizeof(A)/sizeof(0));

	return 0;
}


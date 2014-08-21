/*************************************************************************
       File: combination_sum.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-13 23:56:46

Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
************************************************************************/

#include "tools.h"

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int> &c, int target)
	{
		vector<vector<int>> result;
		sort(c.begin(), c.end());
		vector<int> solution;
		combinationSum(c, 0, target, solution, result);

		return result;
	}

	void combinationSum(vector<int> &c, int start, int target, 
			vector<int> &solution, vector<vector<int>> &result)
	{
		if(start >= c.size() || target < c[start])	return ;
		solution.push_back(c[start]);
		if(c[start] == target)
		{
			result.push_back(solution);
		} else {
			combinationSum(c, start, target-c[start], solution, result);	// includes c[start]
		}
		solution.pop_back();
		combinationSum(c, start+1, target, solution, result);	// not includes c[start]
	}
};

int main()
{
	int A[] = {2,3,5};
	vector<int> c(&A[0], &A[0]+sizeof(A)/sizeof(0));

	vector<vector<int>> result = (new Solution())->combinationSum(c, 7);
	print(result);
}

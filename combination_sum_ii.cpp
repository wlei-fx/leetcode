/*************************************************************************
       File: combination_sum_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-24 15:45:56

Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
************************************************************************/

#include "tools.h"

class Solution
{
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target)
	{
		vector<vector<int>> result;
		vector<int> solution;
		sort(num.begin(), num.end());

		combinationSum2(num, target, 0, solution, result);
		return result;
	}

	void combinationSum2(vector<int> &num, int target, int start, vector<int> &solution, 
			vector<vector<int>> &result)
	{
		if(0 == target) {
			result.push_back(solution);
			return ;
		}

		if(start >= num.size() || target < num[start])
			return ;

		solution.push_back(num[start]);
		combinationSum2(num, target-num[start], start+1, solution, result);
		solution.pop_back();
		while(start < num.size()-1 && num[start+1] == num[start]) start++;
		combinationSum2(num, target, start+1, solution, result);
	}
};

int main()
{
	int A[] = {10,1,2,7,6,1,5};
	vector<int> num(A, A+sizeof(A)/sizeof(0));

	vector<vector<int>> result = (new Solution())->combinationSum2(num, 8);
	print(result);
}


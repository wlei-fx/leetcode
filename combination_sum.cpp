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

#include "helper.h"

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int> &c, int target)
	{
		vector<vector<int>> result;
		vector<int> solution;
		sort(c.begin(), c.end());
		combinationSum(c, 0, target, solution, result);

		return result;
	}

	void combinationSum(vector<int> &c, int start, int target, 
			vector<int> &solution, vector<vector<int>> &result)
	{
		cout<<start<<" "<<target<<endl;
		print(solution);
		cout<<">>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
		for(int i = start; i < c.size(); i++)
		{
			if(target < c[i])	return ;
			//if(i != start && c[i] == c[i-1])	continue ;
			solution.push_back(c[i]);
			if(c[i] == target)
			{
				cout<<start<<" "<<target<<endl;
				print(solution);
				cout<<".................."<<endl;
				result.push_back(solution);
			} else {
				combinationSum(c, i, target-c[i], solution, result);
				combinationSum(c, i+1, target-c[i], solution, result);
			}
			solution.pop_back();
		}
	}
};

int main()
{
	int A[] = {2,3,6,7};
	vector<int> c(&A[0], &A[0]+sizeof(A)/sizeof(0));

	print((new Solution())->combinationSum(c, 9));
}

/*************************************************************************
       File: subsets_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-13 23:56:28

Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
************************************************************************/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<vector<int> > subsets(vector<int> &s) {
		vector<int> solution;
		vector<vector<int> > result(1, solution);

		sort(s.begin(), s.end());
		subsets(s, 0, solution, result);
		return result;
	}

	void subsets(vector<int> &s, int start, vector<int> &solution, vector<vector<int> > &result)
	{
		if(start == s.size())
		{
			return ;
		}

		subsets(s, start+1, solution, result);								// find subsets not including start
		solution.push_back(s[start]);										
		result.push_back(solution);
		subsets(s, start+1, solution, result);								// find subsets including start
		solution.pop_back();
	}
};

int main()
{
	int A[] = {1,2,2};
	vector<int> s(&A[0], &A[0]+sizeof(A)/sizeof(0));

	vector<vector<int> > result = (new Solution())->subsets(s);

	for(auto iter = result.begin(); iter != result.end(); iter++)
	{
		cout<<"[";
		for(auto itr = (*iter).begin(); itr != (*iter).end(); itr++)
		{
			cout<<*itr<<",";
		}
		cout<<"]"<<endl;
	}
}

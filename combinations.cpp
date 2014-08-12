/*
Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combine(int n, int k) {
		vector<int> solution;
		vector<vector<int> > result;

		combine(1, n, k, k, solution, result);
		return result;
	}

	void combine(int start, int n, int k, int level, vector<int> &solution, vector<vector<int> > &result)
	{
		if(k == solution.size())										// find one
		{
			result.push_back(solution);
			return ;
		}

		if(level > n - start + 1)										// left element not enough
		{
			return ;
		}

		solution.push_back(start);										// find combinations including start
		combine(start+1, n, k, level-1, solution, result);
		solution.pop_back();
		combine(start+1, n, k, level, solution, result);				// find combinations not including start
	}
};

int main()
{
	int n, k;
	cin>>n>>k;

	vector<vector<int> > result = (new Solution())->combine(n, k);

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

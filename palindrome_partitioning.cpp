/*************************************************************************
       File: palindrome_partitioning.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-13 23:57:49

Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
[
    ["aa","b"],
	["a","a","b"]
]
************************************************************************/

#include "tools.h"

class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> result;
		vector<string> solution;

		partition(s, 0, solution, result);
		return result;
	}

	void partition(string &s, int start, vector<string> &solution, vector<vector<string>> &result)
	{
		if(start == s.size())	// found one
		{
			result.push_back(solution);
			return ;
		}
		for(int i = start+1; i <= s.size(); i++)	// 依次考虑长度为1,2,3,..的子串是否是回文串
		{
			if(isPalindrome(s, start, i))			// 如果是，就递归的求后面部分的所有回文分割
			{
				solution.push_back(s.substr(start, i-start));
				partition(s, i, solution, result);
				solution.pop_back();
			}
		}
	}

	bool isPalindrome(string &s, int start, int end)
	{
		while(start < end)
		{
			if(s[start] != s[end-1])
				return false;

			start++, end--;
		}

		return true;
	}
};

int main()
{
	string s;
	cin>>s;
	vector<vector<string>> result = (new Solution())->partition(s);
	print(result);
	return 0;
}


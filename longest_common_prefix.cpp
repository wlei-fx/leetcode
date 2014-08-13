/*************************************************************************
       File: longest_common_prefix.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-12 22:08:11

Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		if(0 == strs.size())
			return "";

		string left = strs[0];
		for(int i = 1; i < strs.size(); i++)
		{
			left = longestCommonPrefix(left, strs[i]);
		}

		return left;
	}

	string longestCommonPrefix(string &left, string &right)
	{
		int i = 0;
		while(i < left.size() && i < right.size() && left[i] == right[i]) i++;

		return left.substr(0, i);
	}
};

int main()
{
	string strs[] = {"document", "download", "idocuments"};
	vector<string> str(&strs[0], &strs[0]+sizeof(strs)/sizeof(string));

	cout<<(new Solution())->longestCommonPrefix(str);
}

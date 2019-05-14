/*************************************************************************
       File: palindrome_partitioning_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-10 13:58:23

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

************************************************************************/
#include "tools.h"

class Solution {
public:
    int minCut(string s)
	{
        vector<int> scuts(s.size()+1, INT_MAX);
		return minCut(s, 0, 0, scuts)-1;
	}

	int minCut(string &s, int start, int cuts, vector<int> &scuts)
	{
        int minCuts = INT_MAX;
		if(start == s.size())	// found one
		{
			return cuts;
		}
		for(int i = start+1; i <= s.size(); i++)	// 依次考虑长度为1,2,3,..的子串是否是回文串
		{
			if(isPalindrome(s, start, i))			// 如果是，就递归的求后面部分的所有回文分割
			{
                
				int c = 1 + cuts;
                if (scuts[i] == INT_MAX) {
                    scuts[i] = minCut(s, i, 0, scuts);
                }
                
                c += scuts[i];
                minCuts = min(minCuts, c);
			}
		}
        
        return minCuts;
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

int main() {
    string s = "ababababababababababababcbabababababababababababa";
    cout<<Solution().minCut(s)<<endl;
}

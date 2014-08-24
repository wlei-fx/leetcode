/*************************************************************************
       File: distinct_subsequences.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-24 14:17:15

Distinct Subsequences
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"
Return 3.
************************************************************************/

#include "tools.h"

class Solution
{
public:
	int numDistinct(string S, string T)
	{
		//return numDistinct(S, 0, S.size(), T, 0, T.size());
		return numDistinct_dp(S, T);
	}

	int numDistinct(string &s, int ss, int se, string &t, int ts, int te)
	{
		if(ts == te)		// 找到一个
			return 1;
		if(ss == se)		// s找到最后没有找到
			return 0;

		int num = 0;
		if(s[ss] == t[ts]) {
			num += numDistinct(s, ss+1, se, t, ts+1, te);	// 递归找后面的子串出现的次数
		}
		num += numDistinct(s, ss+1, se, t, ts, te);			// 缩小s的规模继续找

		return num;
	}

	// 动态规划
	int numDistinct_dp(string S, string T)
	{
		int m = S.size(), n = T.size();
		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[0][0] = S[0] == T[0] ? 1 : 0;
		for(int i = 1; i < m; i++)
			dp[i][0] = S[i] == T[0] ? 1 + dp[i-1][0] : dp[i-1][0];
		
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j <= i && j < n; j++)
			{
				dp[i][j] = S[i] == T[j]
					? dp[i-1][j-1] + dp[i-1][j]
					: dp[i-1][j];
			}
		}

		return dp[m-1][n-1];
	}
};

int main()
{
	string S, T;
	Solution *s = new Solution;
	while(cin>>S>>T)
		cout<<s->numDistinct(S, T)<<endl;
	return 0;
}

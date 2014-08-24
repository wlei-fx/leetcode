/*************************************************************************
       File: edit_distance.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-24 00:28:30

Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
************************************************************************/

#include "tools.h"

class Solution
{
public:
	int editDistance(string word1, string word2)
	{
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

		for(int i = 0; i <= n; i++)
			dp[0][i] = i;
		for(int i = 0; i <= m; i++)
			dp[i][0] = i;

		// 动态规划
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				dp[1+i][1+j] = word1[i] == word2[j]
					? min(dp[i][j], 1+min(dp[1+i][j], dp[i][1+j])) 
					: 1 + min(dp[i][j], min(dp[1+i][j], dp[i][1+j]));
			}
		}

		return dp[m][n];
	}
};

int main()
{
	string s1, s2;
	cin>>s1>>s2;
	cout<<(new Solution())->editDistance(s1, s2);
	return 0;
}

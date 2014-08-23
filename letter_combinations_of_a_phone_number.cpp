/*************************************************************************
       File: letter_combinations_of_a_phone_number.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-13 23:57:14

Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
0:			1:			2: abc			3: def			4: ghi
5: jkl		6: mno		7: pqrs			8: tuv			9: wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
************************************************************************/

#include "tools.h"

string maps[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> result;

		letterCombinations(digits, 0, "", result);
		return result;
	}

	void letterCombinations(string &digits, int i, 
			string str, vector<string> &result)
	{
		if(i == digits.size())
		{
			result.push_back(str);
			return ;
		}
		for(int j = 0; j < maps[digits[i]-'0'].size(); j++)		// depth-first search
		{
			letterCombinations(digits, i+1, str+maps[digits[i]-'0'][j], result);
		}
	}
};

int main()
{
	string s;
	cin>>s;
	vector<string> result = (new Solution())->letterCombinations(s);
	print(result);
}

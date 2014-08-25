/********************************************
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

For example,
Given ["abc", "bca", "acb", "aabc", "caba", "bbb"],
return ["abc", "bca", "acb", "aabc", "caba"]
********************************************/

#include "tools.h"

class Solution
{
public:
	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> result;
		vector<string> tmp(strs);

		// 对每一个str按字典顺序排序
		for_each(tmp.begin(), tmp.end(), [](string &str) {
			sort(&str[0], &str[0]+str.size());
		});

		// 用map记录每一个排序的str出现的次数
		unordered_map<string, int> map;
		for_each(tmp.begin(), tmp.end(), [&map](string &str){
			auto iter = map.find(str);
			if(map.end() == iter)
			{
				map.insert({str, 0});
			} else {
				iter->second++;
			}
		});

		for(int i = 0; i < strs.size(); i++)
		{
			if(map.find(tmp[i])->second > 0)
			{
				result.push_back(strs[i]);
			}
		}

		return result;
	}
};

int main()
{
	string strs[] = {"abc", "bac", "acb", "bbac", "cabb", "bbb"};
	vector<string> vstrs(strs, strs+sizeof(strs)/sizeof(strs[0]));
	vector<string> result = (new Solution())->anagrams(vstrs);
	print(result);
}

/*************************************************************************
       File: count_and_say.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-12 22:08:46

Count and Say 
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
************************************************************************/

#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Solution
{
public:
	string countAndSay(int n)
	{
		stringstream ss;
		string curStr("1");
		
		while(--n)
		{
			for(int i = 0; i < curStr.size();)
			{
				int j = i, cnt = 0;
				while(j < curStr.size() && curStr[j] == curStr[i]) j++, cnt++;
				ss<<cnt<<curStr[i];
				i = j;
			}
			ss>>curStr;
			ss.clear();
		}

		return curStr;
	}
};

int main()
{
	int n;
	cin>>n;

	cout<<(new Solution())->countAndSay(n);
}

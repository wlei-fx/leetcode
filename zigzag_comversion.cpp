/*************************************************************************
       File: zigzag_comversion.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-24 17:33:53

ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
************************************************************************/

#include "tools.h"

class Solution
{
public:
	string convert(string s, int rows)
	{

	}
};

int main()
{
	string str;
	int rows;
	Solution *s = new Solution;
	while(cin>>s>>rows)
		cout<<s->convert(str, rows);

	return 0;
}


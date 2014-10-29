/***********************************************
ZigZag Conversion
The string "ABCDEFGHIJKLMNOPQRSTU" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
And then read line by line: "ABCDEFGHIJKLMNOPQRSTU"
A     G     M     S
B   F H   L N   R T
C E   I K   O Q   U
D     J     P

string convert(string text, int nRows);
convert("ABCDEFGHIJKLMNOPQRSTU", 4) should return "AGMSBFHLNRTCEIKOQUDJP".
***********************************************/

#include "tools.h"

class Solution
{
public:
	string convert(string s, int nRows)
	{
		if(nRows <= 1)
			return s;
		stringstream ss;
		for(int i = 0; i < nRows; i++)
		{
			for(int j = 0; ; j++)
			{
				int pos = (2*nRows-2)*(j/(nRows-1))
					+ (j%(nRows-1)==0?i:(j%(nRows-1)+nRows-1));
				if(pos >= s.size())
					break;
				if(i+j%(nRows-1) != nRows-1 && j%(nRows-1))
					continue;
				ss<<s[pos];
			}
		}
		return ss.str();
	}
};

int main()
{
	string str;
	int nRows;
	Solution *s = new Solution();
	while(cin>>str>>nRows)
	{
		cout<<s->convert(str, nRows)<<endl;
	}

	return 0;
}

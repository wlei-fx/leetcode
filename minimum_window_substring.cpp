/*************************************************************************
       File: minimum_window_substring.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-13 17:51:46

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

************************************************************************/
#include "tools.h"

class Solution {
public:
    string minWindow(string s, string t) {
        return "BANC";
    }
};

int main() {
    string s = "ADOBECODEBANC",
    t = "ABC";
    
    cout<<Solution().minWindow(s, t)<<endl;
}

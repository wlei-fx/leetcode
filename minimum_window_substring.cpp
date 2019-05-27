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
        vector<int> sv(256, 0);
        vector<int> tv(256, 0);
        int len = 0, start = 0;
        string mw;
        
        for (int i = 0; i < t.size(); i++) {
            tv[t[i]] += 1;
        }
        
        for (int i = 0; i < s.size(); i++) {
            cout<<"i="<<i<<", s[i]="<<s[i]<<", start="<<start<<", "<<s.substr(start)<<endl;            
            if (0 >= tv[s[i]]) continue;
            
            if (tv[s[i]] > sv[s[i]]) {
                start = 0 == len ? i : start;
                sv[s[i]] += 1;
                len += 1;
            } else {
                sv[s[i]] += 1;
                for (; start <= i; start++) {
                    if (tv[s[start]] > 0 && tv[s[start]] >= sv[s[start]]) {
                        break;
                    } else {
                        sv[s[start]] -= 1;
                    }
                }
            }
            
            if (len == t.size()) {
                string b = s.substr(start, i-start+1);
                mw = mw.size() > 0 ? (mw.size() > b.size() ? b : mw) : b;
                
                sv[s[start]] -= 1;
                len -= 1;
                for (start += 1; start <= i; start++) {
                    cout<<tv[s[start]]<<"\t"<<sv[s[start]]<<endl;
                    if (tv[s[start]] > 0 && tv[s[start]] >= sv[s[start]]) {
                        break;
                    } else {
                        sv[s[start]] -= 1;
                    }
                }
            }
            
        }
        
        return mw;
    }
};

int main() {
    string 
    // s = "ADOBECODEBANC",
    // t = "ABC"
    s = "aa",
    t = "aa"
    // s = "a",
    // t = "a"
    // s = "acbbaca",
    // t = "aba"
    ;
    
    cout<<s<<"\t"<<t<<endl;
    cout<<Solution().minWindow(s, t)<<endl;
}

/*************************************************************************
       File: scramble_string.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-10 17:23:21

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false

************************************************************************/
#include "tools.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        
        map<string, bool> searched;
        
        return isScramble(s1, s2, searched);
    }
    
    bool isScramble(string s1, string s2, map<string, bool> &searched) {
        // cout<<s1<<" "<<s2<<":"<<endl;
        if (1 == s1.size()) {
            // cout<<s1<<" "<<s2<<" -> "<<(s1[0] == s2[0] ? "true" : "false")<<endl;
            return s1[0] == s2[0];
        }
        
        if (s1 == s2) {
            // cout<<s1<<" "<<s2<<" -> true"<<endl;
            return true;
        }
        
        for (int i = 1; i < s1.size(); i++) {
            string a = s1.substr(0, i), b = s1.substr(i);
            string m = s2.substr(0, i), n = s2.substr(i), p = s2.substr(0, s2.size()-i), q = s2.substr(s2.size()-i);
            // cout<<"a: "<<a<<"\tb: "<<b<<"\tm: "<<m<<"\tn: "<<n<<"\tp: "<<p<<"\tq: "<<q<<endl;
            bool r1, r2, r3, r4;
            map<string, bool>::iterator it;
            if ((it = searched.find(a+"-"+m)) != searched.end()) {
                r1 = it->second;
            } else {
                r1 = isScramble(a, m, searched);
                searched[a+"-"+m] = r1;
            }
            
            if (r1) {
                if ((it = searched.find(b+"-"+n)) != searched.end()) {
                    r2 = it->second;
                } else {
                    r2 = isScramble(b, n, searched);
                    searched[b+"-"+n] = r2;
                }
            }
            
            if (r1 && r2) {
                // cout<<s1<<" "<<s2<<" -> true"<<endl;
                return true;
            } 
            
            if ((it = searched.find(a+"-"+q)) != searched.end()) {
                r3 = it->second;
            } else {
                r3 = isScramble(a, q, searched);
                searched[a+"-"+q] = r3;
            }
            
            if (r3) {
                if ((it = searched.find(b+"-"+p)) != searched.end()) {
                    r4 = it->second;
                } else {
                    r4 = isScramble(b, p, searched);
                    searched[b+"-"+p] = r4;
                }
            }
            
            if (r3 && r4) {
                // cout<<s1<<" "<<s2<<" -> "<<(r3 && r4 ? "true" : "false")<<endl;
                return true;
            }
        }
        // cout<<s1<<" "<<s2<<" -> false"<<endl;
        return false;
    }
};

int main() {
    // string s1 = "great", 
    // s2 = "rgtae";
    
    // string s1 = "abcde", 
    // s2 = "caebd";
    
    string s1 = "abcdefghijklmnopq",
    s2 = "efghijklmnopqcadb";
    
    cout<<Solution().isScramble(s1, s2)<<endl;
}

/*************************************************************************
       File: interleaving_string.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 19:52:50

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

************************************************************************/
#include <vector>
#include <string>
#include <iostream>
#include "tools.h"
using namespace std;

// class Solution {
// public:    
//     bool isInterleave(string s1, string s2, string s3) {
//         if (s1.size() + s2.size() != s3.size()) {
//             return false;
//         }
// 
//         vector<int> p(s3.size(), -1);
//         int i = 0, j = 0;
// 
//         while (i <= s1.size() && j <= s2.size()) {
//             if (i == s1.size() && j == s2.size()) {
//                 return true;
//             }
// 
//             for (int i = 0; i < p.size() && p[i] != -1; i++) {
//                 cout<<p[i];
//             }
//             cout<<endl;
//             if (i < s1.size() && s1[i] == s3[i+j]) {
//                 p[i+j] = 0;
//                 i++;
//             } else if (j < s2.size() && s2[j] == s3[i+j]) {
//                 p[i+j] = 1;
//                 j++;
//             } else {
//                 if (i == 0 && j == 0) {
//                     return false;
//                 }
//                 while (i >= 0 && j >= 0) {
//                     if (p[i+j-1] == 1) {
//                         p[i+j-1] = -1;
//                         j--;
//                     } else if (s2[j] == s3[i+j-1]) {
//                         p[i+j-1] = 1;
//                         i--, j++;
//                         break;
//                     } else {
//                         p[i+j-1] = -1;
//                         i--;
//                     }
//                 }
//             }
//         }
// 
//         return false;
//     }
// };


class Solution {
public:    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
    
    bool isInterleave(string s1, string s2, string s3, int i, int j , int k) {
        cout<<s1.substr(i)<<"\t"<<s2.substr(j)<<"\t"<<s3.substr(k)<<endl;
        if (i == s1.size() && j == s2.size()) {
            return k == s3.size();
        }
        if (i == s1.size()) {
            return s2[j] == s3[k] && isInterleave(s1, s2, s3, i, j+1, k+1);
        }
        if (j == s2.size()) {
            return s1[i] == s3[k] && isInterleave(s1, s2, s3, i+1, j, k+1);
        }
        
        if (s1[i] != s2[j]) {
            return s1[i] == s3[k] ? isInterleave(s1, s2, s3, i+1, j, k+1) : 
                (s2[j] == s3[k] ? isInterleave(s1, s2, s3, i, j+1, k+1) : false);
        }
        
        if (s1[i] != s3[k]) {
            return false;
        }
        
        int nk = k+1;
        while(nk < s3.size() && s3[nk] == s3[k]) nk++;
        
        if (nk == s3.size()) {
            while(i < s1.size() && s1[i] == s3[k]) i++;
            while(j < s2.size() && s2[j] == s3[k]) j++;
            
            return i == s1.size() && j == s2.size();
        }
        
        int ni = i, nj = j;
        while (ni < s1.size() && s1[ni] == s3[k]) ni++;
        while (nj < s2.size() && s2[nj] == s3[k]) nj++;
        
        if (ni == s1.size() && nj == s2.size()) {
            return false;
        }
        
        if (ni == s1.size()) {
            return (nk-k <= nj-j+ni-i) ? isInterleave(s1, s2, s3, i+nk-k-nj+j, nj+1, nk+1) : false;
        }
        if (nj == s2.size()) {
            return (nk-k <= nj-j+ni-i) ? isInterleave(s1, s2, s3, ni+1, j+nk-k-ni+i, nk+1) : false;
        }
        
        if (nj-j > nk-k && ni-i > nk-k) {
            return false;
        }
        
        return (ni-i <= nk-k && s1[ni] == s3[nk] && isInterleave(s1, s2, s3, ni+1, j+nk-k-ni+i, nk+1))
            || (nj-j <= nk-k && s2[nj] == s3[nk] && isInterleave(s1, s2, s3, i+nk-k-nj+j, nj+1, nk+1));
    }
};


int main() {
    string 
    // s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", 
    // s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", 
    // s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    
    // string s1 = "aabcc",
    // s2 = "dbbca",
    // s3 = "aadbbcbcac";
    
    // string s1 = "aabcc",
    // s2 = "dbbca",
    // s3 = "aadbbbaccc";
    
    // string s1 = "aabd",
    // s2 = "abdc",
    // s3 = "aabdabcd";
    
    s1 = "aacaac",
    s2 = "aacaaeaac",
    s3 = "aacaaeaaeaacaac";
    
    cout<<Solution().isInterleave(s1, s2, s3)<<endl;
}

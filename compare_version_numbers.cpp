/*************************************************************************
       File: compare_version_numbers.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-14 18:51:49

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.

************************************************************************/
#include "tools.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p = 0, q = 0, v1 = 0, v2 = 0;
        
        while (p < version1.size() && q < version2.size()) {
            while(version1[p] != '.' && p < version1.size()) v1 = v1 * 10 + version1[p++]-'0';
            while(version2[q] != '.' && q < version2.size()) v2 = v2 * 10 + version2[q++]-'0';
            
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
            
            p++, q++;
            v1 = 0, v2 = 0;
        }
        cout<<p<<"   "<<q<<endl;
        if (p >= version1.size() && q >= version2.size()) return 0;
        if (p >= version1.size()) {
            while(q < version2.size()) {
                if (version2[q] != '0' && version2[q] != '.') return -1;
                q++;
            }
            return 0;
        }
        
        while(p < version1.size()) {
            if (version1[p] != '0' && version1[p] != '.') return 1;
            p++;
        }
        return 0;
    }
};

int main() {
    cout<<Solution().compareVersion("1.01.1", "1.001.01")<<endl;
}

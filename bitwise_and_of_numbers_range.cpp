/*************************************************************************
       File: bitwise_and_of_numbers_range.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-16 10:37:07

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

************************************************************************/
#include "tools.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int r = m & n;
        for (int i = 0; i < 31; i++) {
            if (n - (1 << i) >= m) {
                r &= ~(1 << i);
            } else {
                break;
            }
        }
        
        return r;
    }
};

int main() {
    // int m = 2147483646, n = 2147483647;
    // int m = 5, n = 7;
    int m = 1, n = 2147483647;
    cout<<Solution().rangeBitwiseAnd(m, n)<<endl;
}

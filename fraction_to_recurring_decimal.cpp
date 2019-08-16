/*************************************************************************
       File: fraction_to_recurring_decimal.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-15 10:21:12

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

************************************************************************/
#include "tools.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {    
        int nSign = numerator < 0 ? -1 : 1;
        int dSign = denominator < 0 ? -1 : 1;
        long long n = numerator, d = denominator;
        n = abs(n), d = abs(d);
        
        unordered_map<int, int> m;
        string r = to_string(n / d);
        n = n % d;
        
        if (n) r += ".";
        
        while(n) {
            auto iter = m.find(n);
            if (iter != m.end()) {
                r.insert(iter->second, "(");
                r += ")";
                break;
            }
            m[n] = r.size();
            n *= 10;
            r += to_string(n / d);
            n = n % d;
        }
        
        if (nSign * dSign == -1 && r != "0") r = "-" + r;
        
        return r;
    }
};

int main() {
    cout<<Solution().fractionToDecimal(0, 11)<<endl;
    // cout<<Solution().fractionToDecimal(1, 11)<<endl;
    // cout<<Solution().fractionToDecimal(-1, -2147483648)<<endl;
}

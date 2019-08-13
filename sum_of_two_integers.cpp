/*************************************************************************
       File: sum_of_two_integers.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-09 14:49:53



************************************************************************/
#include "tools.h"

class Solution {
public:
    int getSum(int a, int b) {
        int sa = a & (1<<31), sb = b & (1<<31);
        
        if(sa != 0 && sb != 0) {
            a = -a, b = -b;
        } else {
            a ^= sa, b ^= sb;
        }
        
        int c, d;
        
        do {
            c = a & b;
            d = a ^ b;
            
            a = c << 1;
            b = d;
        } while(c != 0 && !(a & (1<<31)));

        if (sa != 0 && sb != 0)
            return sa | (-d);
        
        if (sa == 0 && sb == 0)
            return sa | d;
        
        return (sa ^ sb ^ (a & (1<<31))) | d;
    }
};

int main() {
    cout<<Solution().getSum(-6,-5)<<endl;
}

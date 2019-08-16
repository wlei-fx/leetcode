/*************************************************************************
       File: best_time_to_buy_and_sell_stock_iv.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-15 16:27:32

Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

************************************************************************/
#include "tools.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;
        
        vector<int> sp;
        
        int p = -1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i-1]) {
                p = p == -1 ? (i-1) : p;
                if (i == prices.size()-1) {
                    sp.push_back(prices[p]);
                    sp.push_back(prices[i]);
                }
            } else if (p != -1 && p != i-1) {
                sp.push_back(prices[p]);
                sp.push_back(prices[i-1]);
                p = -1;
            } else {
                p = i;
            }
        }

        print(sp);
        while(sp.size() > k * 2) {
            int p = -1, m_ax = INT_MIN;
            for (int i = 0; i <= sp.size()-4; i+=2) {
                int m = sp[i+3] - sp[i], l = sp[i+1] - sp[i], r = sp[i+3] - sp[i+2];
                if (m >= l && m >= r) {
                    m = min(m-l, m-r);
                    if (m > m_ax) {
                        m_ax = m;
                        p = i;
                    }
                }
            }
                        
            if (p == -1) break;
            
            cout<<"erase "<<p<<endl;
            sp.erase(sp.begin()+p+1, sp.begin()+p+3);
            print(sp);
        }

        vector<int> profits;
        for (int i = 0; i <= ((int)sp.size())-2; i+=2) {
            profits.push_back(sp[i+1] - sp[i]);
        }
        
        sort(profits.begin(), profits.end());
        
        int profit = 0;

        for (int i = profits.size()-1; i >= 0 && k--; i--) {
            profit += profits[i];
        }

        return profit;
    }
};

int main() {
    int k = 2;
    // vector<int> prices = {2, 4, 1};
    // vector<int> prices = {3,2,6,5,0,3};
    // vector<int> prices = {1,2,4};
    // vector<int> prices = {3,3,5,0,0,3,1,4};
    // vector<int> prices = {2,6,8,7,8,7,9,4,1,2,4,5,8};
    vector<int> prices = {8,6,4,3,3,2,3,5,8,3,8,2,6};
    
    // int k = 1;
    // vector<int> prices = {6,1,6,4,3,0,2};
    // vector<int> prices = {1,2};
    // vector<int> prices;
    
    cout<<Solution().maxProfit(k, prices)<<endl;
}

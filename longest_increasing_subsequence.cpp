/*************************************************************************
       File: longest_increasing_subsequence.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-09 16:59:13

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

************************************************************************/
#include "tools.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        vector<int> ls(nums.size(), 0);
        
        int ll = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    ls[i] = max(ls[i], ls[j]+1);
                    ll = max(ll, ls[i]);
                }
            }
        }
        
        return ll+1;
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<Solution().lengthOfLIS(nums)<<endl;
}

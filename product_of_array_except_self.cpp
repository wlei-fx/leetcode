/*************************************************************************
       File: product_of_array_except_self.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-09 17:21:06

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space 
for the purpose of space complexity analysis.)

************************************************************************/
#include "tools.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l = vector<int>(nums.size(), 1);
        vector<int> r = vector<int>(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++) {
            l[i] = nums[i-1] * l[i-1];
        }
        
        for(int i = nums.size()-2; i >= 0; i--) {
            r[i] = nums[i+1] * r[i+1];
        }
        
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            res[i] = l[i] * r[i];
        }
        
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> res = Solution().productExceptSelf(nums);
    print(res);
}

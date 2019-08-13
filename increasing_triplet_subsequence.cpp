/*************************************************************************
       File: increasing_triplet_subsequence.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-09 16:03:22

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false

************************************************************************/
#include "tools.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;

        int minNum = nums[0], maxNum = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            if (maxNum == INT_MIN) {
                if (nums[i] > minNum) {
                    maxNum = nums[i];
                } else {
                    minNum = nums[i];
                }
            } else {
                if (nums[i] > maxNum) {
                    return true;
                } else if (nums[i] < minNum) {
                    minNum = nums[i];
                } else if (nums[i] > minNum && nums[i] < maxNum) {
                    maxNum = nums[i];
                }
            }
            
            cout<<i<<'\t'<<minNum<<'\t'<<maxNum<<endl;
        }
        
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,1,2,1,2,1,2};
    cout<<Solution().increasingTriplet(nums)<<endl;
}

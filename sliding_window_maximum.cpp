/*************************************************************************
       File: sliding_window_maximum.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-09 17:57:26

Given an array nums, there is a sliding window of size k which is moving from the very 
left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

************************************************************************/
#include "tools.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> r;
        
        if (nums.size() == 0) return r;
        
        int maxNum = INT_MAX;
        for (int i = 0; i < nums.size()-k+1; i++) {
            if (nums[i+k-1] >= maxNum) {
                maxNum = nums[i+k-1];
                r.push_back(maxNum);
            } else if (i > 0 && nums[i-1] < maxNum) {
                r.push_back(maxNum);
            } else {
                maxNum = nums[i];
                for (int j = 1; j < k; j++) {
                    maxNum = max(maxNum, nums[i+j]);
                }
                r.push_back(maxNum);
            }
        }
        
        return r;
    }
};

int main() {
    vector<int> nums ;
    int k = 3;
    vector<int> r = Solution().maxSlidingWindow(nums, k);
    print(r);
}

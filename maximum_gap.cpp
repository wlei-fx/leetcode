/*************************************************************************
       File: maximum_gap.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-13 18:23:35

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.

************************************************************************/
#include "tools.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        return maximumGap(nums, 30);
    }
    
    int maximumGap(vector<int>& nums, int highBit) {
        int maxGap = 0, pmax = 0;
        vector<bool> tags(nums.size(), false);
    
        for (int i = highBit; i >= 0; i--) {
            int bit = 1 << i, cmin = INT_MAX, cmax = 0;
            vector<int> curLevel;
            for (int i = 0; i < nums.size(); i++) {
                if (tags[i] || !(nums[i] & bit)) continue;
    
                cmin = min(cmin, nums[i]);
                cmax = max(cmax, nums[i]);
                curLevel.push_back(nums[i] - bit);
                tags[i] = true;
            }
    
            if (!curLevel.empty()) {
                maxGap = max(maxGap, pmax - cmax);
            }
    
            if (1 == curLevel.size() || cmax == cmin) {
                pmax = curLevel[0] + bit;
            } else if (!curLevel.empty()) {
                maxGap = max(maxGap, maximumGap(curLevel, highBit-1));
            }
    
            pmax = INT_MAX == cmin ? pmax : cmin;
        }
    
        return maxGap;
    }
};

int main() {
    vector<int> nums =
     // {9, 1, 3, 6, 20};
     // {1, 1, 1, 1};
     {100, 3, 2, 1};
     // {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    
    
    
    cout<<Solution().maximumGap(nums)<<endl;
}

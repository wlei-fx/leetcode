/*************************************************************************
       File: largest_rect_in_histogram.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 15:54:36

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
************************************************************************/

#include <vector>
#include <iostream>
#include "tools.h"
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> lh(heights.size()), rh(heights.size());
        
        for (int i = 1; i < heights.size(); i++) {
            int j = i - 1;
            while(j >= 0 && heights[j] >= heights[i]) {
                lh[i] += lh[j]+1;
                j = i -lh[i] - 1;
            }
        }

        for (int i = heights.size()-2; i >= 0; i--) {
            int j = i + 1;
            while(j < heights.size() && heights[j] >= heights[i]) {
                rh[i] += rh[j]+1;
                j = i + rh[i] + 1;
            }
        }
        
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, (lh[i] + 1 + rh[i])*heights[i]);
        }
        
        return maxArea;
    }
};


int main() {
    int a[] = {4,2,0,3,2,5};
    vector<int> heights(begin(a), end(a));
    
    cout<<Solution().largestRectangleArea(heights);
}

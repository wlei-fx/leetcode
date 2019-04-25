/*************************************************************************
       File: maximal_rect.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 17:12:26

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
************************************************************************/

#include <vector>
#include <iostream>
#include "tools.h"
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.empty()) {
            return 0;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > heights(m, vector<int>(n));
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == m-1) {
                    heights[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    heights[i][j] = matrix[i][j] == '1' ? (1 + heights[i+1][j]) : 0;  
                }
            }
        }
        
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            maxArea = max(maxArea, largestRectangleArea(heights[i]));
        }
        
        return maxArea;
    }
    
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
    char a[][5] = {{'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}};
    
    vector<vector<char> >matrix;
    
    for(int i = 0; i < 4; i++) {
        vector<char> v(begin(a[i]), end(a[i]));
        matrix.push_back(v);
    }
    
    cout<<Solution().maximalRectangle(matrix);
}

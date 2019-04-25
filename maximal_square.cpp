/*************************************************************************
       File: maximal_square.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 18:19:13

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int maxSquare = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> >l(m, vector<int>(n)), u(m, vector<int>(n)), s(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    u[i][j] = (i > 0 ? u[i-1][j] : 0) + 1;
                    l[i][j] = (j > 0 ? l[i][j-1] : 0) + 1;

                    if (i == 0 || j == 0) {
                        s[i][j] = 1;
                    } else {
                        s[i][j] = min(u[i][j], min(l[i][j], s[i-1][j-1]+1));
                    }
                    
                    maxSquare = max(maxSquare, s[i][j] * s[i][j]);
                }
            }
        }
        
        return maxSquare;
    }
};

int main() {
    char a[][5] = {{'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'},};
    
    vector<vector<char> >matrix;
    
    for (int i = 0; i < 4; i++) {
        vector<char> v(begin(a[i]), end(a[i]));
        matrix.push_back(v);
    }
    
    cout<<Solution().maximalSquare(matrix);
}

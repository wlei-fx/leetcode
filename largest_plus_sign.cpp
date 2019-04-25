/*************************************************************************
       File: largest_plus_sign.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 18:42:57

In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
Example 2:

Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.
Example 3:

Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.
Note:

N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)


************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if (N == 0) {
            return 0;
        }
        
        vector<vector<char>> matrix(N, vector<char>(N, '1'));
        
        for (int i = 0; i < mines.size(); i++) {
            matrix[mines[i][0]][mines[i][1]] = '0';
        }
        
        int order = 0;
        int m = N, n = N;
        vector<vector<int> >l(m, vector<int>(n)), u(m, vector<int>(n)),
            r(m, vector<int>(n)), d(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    u[i][j] = (i > 0 ? u[i-1][j] : 0) + 1;
                    l[i][j] = (j > 0 ? l[i][j-1] : 0) + 1;
                }
            }
        }
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    r[i][j] = (j < n-1 ? r[i][j+1] : 0) + 1;
                    d[i][j] = (i < m-1 ? d[i+1][j] : 0) + 1;
                }
                
                order = max(order, min(l[i][j], min(r[i][j], min(u[i][j], d[i][j]))));
            }
        }
        
        return order;
    }
};

int main() {
    int N = 3;
    int a[][2] = {{0,0}};
    
    vector<vector<int>> mines;
    
    for (int i = 0; i < 1; i++) {
        vector<int> v(begin(a[i]), end(a[i]));
        mines.push_back(v);
    }
    
    cout<<Solution().orderOfLargestPlusSign(N, mines)<<endl;
}

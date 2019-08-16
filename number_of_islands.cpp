/*************************************************************************
       File: number_of_islands.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-16 10:21:37

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally 
or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

************************************************************************/
#include "tools.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int nr = grid.size(), nc = grid[0].size(), num = 0;
        
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == '1') {
                    num += 1;
                    tagCell(grid, i, j, nr, nc);
                }
            }
        }
        
        return num;
    }
    
    void tagCell(vector<vector<char>>& grid, int r, int c, int nr, int nc) {
        
        grid[r][c] = '0';
        if (r-1 >= 0 && grid[r-1][c] == '1') {
            tagCell(grid, r-1, c, nr, nc);
        }
        
        if (r+1 < nr && grid[r+1][c] == '1') {
            tagCell(grid, r+1, c, nr, nc);
        }
        
        if (c-1 >= 0 && grid[r][c-1] == '1') {
            tagCell(grid, r, c-1, nr, nc);
        }
        
        if (c+1 < nc && grid[r][c+1] == '1') {
            tagCell(grid, r, c+1, nr, nc);
        }
    }
};

int main() {
    
}

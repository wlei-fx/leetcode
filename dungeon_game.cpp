/*************************************************************************
       File: dungeon_game.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-05-28 14:06:25

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned 
in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health 
point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering 
these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's 
health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward 
or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal 
path RIGHT-> RIGHT -> DOWN -> DOWN.

----------------------
|-2(K)|	-3	  |3      |
|-5   |	-10	  |1      |
|10   |	30	  |-5 (P) |
---------------------- 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room 
where the princess is imprisoned.

************************************************************************/
#include "tools.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> a(m+1, vector<int>(n+1, 0));
        vector<vector<int>> ad(m+1, vector<int>(n+1, 0));
        
        a[m-1][n-1] = min(0, dungeon[m-1][n-1]);
        for (int i = m-2; i >= 0; i--) {
            a[i][n-1] = min(0, a[i+1][n-1]+dungeon[i][n-1]);
        }
        
        for (int j = n-2; j >= 0; j--) {
            a[m-1][j] = min(0, a[m-1][j+1]+dungeon[m-1][j]);
        }
        
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                a[i][j] = min(0, max(a[i+1][j], a[i][j+1])+dungeon[i][j]);
            }
        }
        print(a);
        return 1-a[0][0];
    }
};

int main() {
    vector<vector<int>> dungeon = 
        // {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
        // {{0}};
        // {{-200}};
        // {{0, -3}};
        {{1}, {-2}, {1}};
        // {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
        print(dungeon);
    
    cout<<Solution().calculateMinimumHP(dungeon)<<endl;
}

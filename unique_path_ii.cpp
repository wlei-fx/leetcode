/*************************************************************************
       File: unique_path_ii.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-10-12 22:08:04

Unique Paths II

Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int> > &grid)
	{
		vector<vector<int>> result(1+grid.size(), vector<int>(1+grid[0].size(), 0));
		
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); j++) 
			{
				if(grid[i][j])
				{
					result[i+1][j+1] = 0;
				} else {
					result[i+1][j+1] = (0 == i && 0 == j) ? 
						1 : (result[i][j+1] + result[i+1][j]);
				}
			}
		}

		return result[grid.size()][grid[0].size()];
	}
};

int main()
{
	int A[][3] = {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};
cout<<sizeof(A)<<" "<<sizeof(A[0])<<endl;
	vector<vector<int>> grid;
	for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
	{
		grid.push_back(vector<int>(&A[i][0], &A[i][0]+sizeof(A[0])/sizeof(0)));
		cout<<grid[i][0]<<" "<<grid[i][1]<<" "<<grid[i][2]<<endl;
	}
	cout<<(new Solution())->uniquePathsWithObstacles(grid);
}

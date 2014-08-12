/*
Valid Sudoku
Determine if a Sudoku is valid, according to:http://sudoku.com.au/TheRules.aspx
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char> > &board)
	{
		for(int i = 0; i < 9; i++)										// check each row
		{
			int cnt[9] = {0};
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] >= '1' && board[i][j] <= '9')
				{
					if(cnt[board[i][j]-'1'])
					{
						return false;
					} else {
						cnt[board[i][j]-'1'] = 1;
					}
				}
			}
		}
		
		for(int i = 0; i < 9; i++)										// check each column
		{
			int cnt[9] = {0};
			for(int j = 0; j < 9; j++)
			{
				if(board[j][i] >= '1' && board[j][i] <= '9')
				{
					if(cnt[board[j][i]-'1'])
					{
						return false;
					} else {
						cnt[board[j][i]-'1'] = 1;
					}
				}
			}
		}

		for(int i = 0; i < 9; i++)										// check each block
		{
			int cnt[9] = {0};
			for(int j = 0; j < 9; j++)
			{
				int r = i/3*3 + j/3;
				int c = (i%3)*3 + j%3;

				if(board[r][c] >= '1' && board[r][c] <= '9')
				{
					if(cnt[board[r][c]-'1'])
					{
						return false;
					} else {
						cnt[board[r][c]-'1'] = 1;
					}
				}
			}
		}

		return true;
	}
};

int main()
{
	string input[] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
	vector<vector<char> > board;

	for(int i = 0; i < 9; i++)
	{
		vector<char> v;
		for(int j = 0; j < 9; j++)
		{
			v.push_back(input[i][j]);
		}
		board.push_back(v);
	}
	cout<<(new Solution())->isValidSudoku(board)<<endl;
}

/*************************************************************************
       File: word_search.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 14:39:05

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size(), n = board[0].size();
        
        vector<vector<bool> > flags(m, vector<bool>(n, false));
        vector<int> ni, nj, np;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                
                ni.push_back(i);
                nj.push_back(j);
                np.push_back(0);
                
                while(!ni.empty()) {
                    int ci = ni.back(), cj = nj.back(), cp = np.back();
                    if (board[ci][cj] == word[cp]) {
                        
                        if (cp == word.size()-1) {
                            return true;
                        }
                        
                        flags[ci][cj] = true;
                        
                        if (cj+1 < n && flags[ci][cj+1] == false) {
                            ni.push_back(ci);
                            nj.push_back(cj+1);
                            np.push_back(cp+1);
                        }
                        
                        if (cj-1 >= 0 && flags[ci][cj-1] == false) {
                            ni.push_back(ci);
                            nj.push_back(cj-1);
                            np.push_back(cp+1);
                        }
                        
                        if (ci-1 >= 0 && flags[ci-1][cj] == false) {
                            ni.push_back(ci-1);
                            nj.push_back(cj);
                            np.push_back(cp+1);
                        }
                        
                        if (ci+1 < m && flags[ci+1][cj] == false) {
                            ni.push_back(ci+1);
                            nj.push_back(cj);
                            np.push_back(cp+1);
                        }
                        
                    }
                    
                    if (np.back() != cp+1) {
                        flags[ni.back()][nj.back()] = false;
                        ni.pop_back();
                        nj.pop_back();
                        np.pop_back();
                        
                        while (!np.empty() && np.back() == cp-1) {
                            flags[ni.back()][nj.back()] = false;
                            cp = np.back();
                            
                            ni.pop_back();
                            nj.pop_back();
                            np.pop_back();
                        }
                    } 
                }
            }
        }
        
        return false;
    }
};

int main() {
    char chs[][3] = {{'c', 'a', 'a'}, {'a', 'a', 'a'}, {'b', 'c', 'd'}};
    string word = "aab";
    
    
    vector<vector<char> > board;
    
    for (int i = 0; i < 3; i++) {
        vector<char> v;
        
        for (int j = 0; j < 3; j++) {
            v.push_back(chs[i][j]);
        }
        
        board.push_back(v);
    }
    
    cout<<Solution().exist(board, word);
}

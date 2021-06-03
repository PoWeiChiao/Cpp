#include <vector>

// Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<char>>& board, vector<vector<int>>& cp, vector<vector<int>> isVisited, int i, int j) {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && !isVisited[i][j] && board[i][j] == 'O') {
            isVisited[i][j] = 1;
            
        }
    }

    void solve(vector<vector<char>>& board) {
        
    }
};
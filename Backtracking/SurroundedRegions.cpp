#include <vector>

// Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<char>>& board, vector<vector<int>>& isVisited, int i, int j) {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && !isVisited[i][j] && board[i][j] == 'O') {
            isVisited[i][j] = 1;
            backtracking(board, isVisited, i + 1, j);
            backtracking(board, isVisited, i - 1, j);
            backtracking(board, isVisited, i, j + 1);
            backtracking(board, isVisited, i, j - 1);
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<int>> isVisited(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            backtracking(board, isVisited, i, 0);
            backtracking(board, isVisited, i, board[i].size() - 1);
        }
        for (int j = 1; j < board[0].size() - 1; ++j) {
            backtracking(board, isVisited, 0, j);
            backtracking(board, isVisited, board.size() - 1, j);
        }
        for (int i = 1; i < board.size() - 1; ++i) {
            for (int j = 1; j < board[i].size() - 1; ++j) {
                if (board[i][j] == 'O' && !isVisited[i][j]) board[i][j] = 'X';
            }
        }
    }
};
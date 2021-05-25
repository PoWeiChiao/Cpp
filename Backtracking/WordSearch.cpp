#include <vector>

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

using namespace std;

class Solution {
public:
    bool Backtracking(vector<vector<char>>& board, vector<vector<int>>& isVisited, int i, int j, int idx, string word) {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[i].size() && board[i][j] == word[idx] && isVisited[i][j] != 1) {
            if (idx == word.size() - 1) return true;
            isVisited[i][j] = 1;
            bool result = Backtracking(board, isVisited, i - 1, j, idx + 1, word) || Backtracking(board, isVisited, i + 1, j, idx + 1, word) || Backtracking(board, isVisited, i, j - 1, idx + 1, word) || Backtracking(board, isVisited, i, j + 1, idx + 1, word);
            isVisited[i][j] = 0;
            return result;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word.front()) {
                    if (word.size() == 1) return true;
                    vector<vector<int>> isVisited(board.size(), vector<int>(board[i].size(), 0));
                    if (Backtracking(board, isVisited, i, j, 0, word)) return true;
                }
            }
        }
        return false;
    }
};
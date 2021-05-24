#include <string>
#include <vector>

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

using namespace std;

class Solution {
public:
    void helper(vector<vector<string>>& res, vector<string> curr, int row, vector<int> cols, vector<int> diag, vector<int> revs, int n) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        string temp(n, '.');
        for (int i = 0; i < n; ++i) {
            if (cols[i] == 0 && diag[row + i] == 0 && revs[row - i + n - 1] == 0) {
                cols[i] = 1;
                diag[row + i] = 1;
                revs[row - i + n - 1] = 1;
                temp[i] = 'Q';
                curr.push_back(temp);
                helper(res, curr, row + 1, cols, diag, revs, n);
                cols[i] = 0;
                diag[row + i] = 0;
                revs[row - i + n - 1] = 0;
                temp[i] = '.';
                curr.pop_back();
            } 
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 1) {
            res.push_back(vector<string>(1, "Q"));
            return res;
        }
        else if (n == 2 || n == 3) return res;
        vector<string> curr;
        int row = 0;
        vector<int> cols(n, 0);
        vector<int> diag(n * 2 - 1, 0); 
        vector<int> revs(n * 2 - 1, 0);
        helper(res, curr, row, cols, diag, revs, n);
        return res;
    }
};
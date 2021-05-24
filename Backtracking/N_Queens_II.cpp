#include <bitset>

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

using namespace std;

class Solution {
public:
    bitset<20> cols;
    bitset<20> diag;
    bitset<20> revs;

    void helper(int& res, int row, int n) {
        if (row == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (cols[i] == 0 && diag[row + i] == 0 && revs[row - i + n - 1] == 0) {
                cols[i] = 1;
                diag[row + i] = 1;
                revs[row - i + n - 1] = 1;
                helper(res, row + 1, n);
                cols[i] = 0;
                diag[row + i] = 0;
                revs[row - i + n - 1] = 0;
            } 
        }
    }

    int totalNQueens(int n) {
        if (n == 1) return 1;
        else if (n == 2 || n == 3) return 0;
        int res = 0;
        int row = 0;
        helper(res, row, n);
        return res;
    }
};
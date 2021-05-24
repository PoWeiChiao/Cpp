#include <vector>

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<int> row(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                row[j] = row[j - 1] + row[j];
            }
        }
        return row.back();
    }
};
#include <vector>

// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
// In one shift operation:

//     Element at grid[i][j] moves to grid[i][j + 1].
//     Element at grid[i][n - 1] moves to grid[i + 1][0].
//     Element at grid[m - 1][n - 1] moves to grid[0][0].

// Return the 2D grid after applying shift operation k times.

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return grid;
        
        k = k % (m * n);
        if (k == 0) return grid;

        int i = 0;
        int count = 0;
        while (count < m * n) {
            int current = i;
            int prev = grid[current / n][current % n];
            while (true) {
                int next = (current + k) % (m * n);
                int temp = grid[next / n][next % n];
                grid[next / n][next % n] = prev;
                prev = temp;
                current = next;
                count++;
                if (current == i) break;
            }
            i++;
        }
        return grid;
    }
};
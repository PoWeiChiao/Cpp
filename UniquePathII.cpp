#include <vector>

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and space is marked as 1 and 0 respectively in the grid.

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() == 1 && obstacleGrid.back().back() == 1) return 0;
        vector<int> row;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (i == 0) {
                bool isObstacle = false;
                for (int j = 0; j < obstacleGrid[i].size(); ++j) {
                    if (obstacleGrid[i][j] != 1 && !isObstacle) row.push_back(1);
                    else { isObstacle = true; row.push_back(0); }
                }
            }
            else {
                if (obstacleGrid[i].front() == 1) row[0] = 0;
                for (int j = 1; j < obstacleGrid[i].size(); ++j) {
                    if (obstacleGrid[i][j] == 1) row[j] = 0;
                    else row[j] = row[j - 1] + row[j];
                }
            }
        }
        return row.back();
    }
};
#include <vector>

// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
// Return the number of servers that communicate with any other server.

using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& grid, vector<vector<int>>& isVisited, int i, int j, int& count) {
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[i].size() && grid[i][j] && !isVisited[i][j]) {
            count++;
            isVisited[i][j] = 1;
            for (int m = i; m >= 0; --m) DFS(grid, isVisited, m, j, count);
            for (int m = i; m < grid.size(); ++m) DFS(grid, isVisited, m, j, count);
            for (int n = j; n >= 0; --n) DFS(grid, isVisited, i, n, count);
            for (int n = j; n < grid[i].size(); ++n) DFS(grid, isVisited, i, n, count);
        }
    }

    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] && !isVisited[i][j]) {
                    int connected_count = 0;
                    DFS(grid, isVisited, i, j, connected_count);
                    count += connected_count > 1 ? connected_count : 0;
                }
            }
        }
        return count;
    }
};

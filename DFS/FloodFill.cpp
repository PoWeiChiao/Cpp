#include <vector>

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
// Return the modified image after performing the flood fill.

using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& image, vector<vector<int>> isVisited, int row, int col, int newColor, int value) {
        if (row >= 0 && col >= 0 && row < image.size() && col < image[0].size() && !isVisited[row][col] && image[row][col] == value) {
            image[row][col] = newColor;
            isVisited[row][col] = 1;
            DFS(image, isVisited, row + 1, col, newColor, value);
            DFS(image, isVisited, row - 1, col, newColor, value);
            DFS(image, isVisited, row, col + 1, newColor, value);
            DFS(image, isVisited, row, col - 1, newColor, value);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int value = image[sr][sc];
        vector<vector<int>> isVisited(image.size(), vector<int>(image[0].size(), 0));
        DFS(image, isVisited, sr, sc, newColor, value);
        return image;
    }
};
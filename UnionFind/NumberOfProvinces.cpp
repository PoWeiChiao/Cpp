#include <vector>

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

using namespace std;

class Solution {
public:
    class DSU{
    private:
        vector<int> vec;
    public:
        DSU(int n) {
            for (int i = 0; i < n ; ++i) vec.push_back(i);
        };
        int Find(int n) {
            if (n != vec[n]) vec[n] = Find(vec[n]);
            return vec[n];
        };
        void Union(int x, int y) {
            x = Find(x);
            y = Find(y);
            if (x != y) vec[x] = y;
        };
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = i + 1; j < isConnected.size(); ++j) {
                if (isConnected[i][j]) dsu.Union(i, j);
            }
        }
        vector<int> root(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); ++i) {
            root[dsu.Find(i)] = 1;   
        }
        int count = 0;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (root[i]) count++;
        }
        return count;
    }
};
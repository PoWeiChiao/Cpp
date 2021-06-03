#include <vector>

// In this problem, a tree is an undirected graph that is connected and has no cycles.
// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

using namespace std;

class Solution {
public:
    class DSU {
    private:
        vector<int> vec;
    public:
        DSU(int n) {
            for (int i = 0; i < n; ++i) vec.push_back(i);
        };

        int find(int n) {
            if (n != vec[n]) vec[n] = find(vec[n]);
            return vec[n];
        };

        void Union(int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (x < y) vec[y] = x;
                else vec[x] = y;
            }
        };
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(0, 0);
        DSU dsu(edges.size());
        for (int i = 0; i < edges.size(); ++i) {
            if (dsu.find(edges[i].front() - 1) == dsu.find(edges[i].back() - 1)) ans = edges[i];
            else dsu.Union(edges[i].front() - 1, edges[i].back() - 1);
        }
        return ans;
    }
};
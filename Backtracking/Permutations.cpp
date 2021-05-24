#include <vector>

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

using namespace std;

class Solution {
public:
    void Backtracking(vector<vector<int>>& res, vector<int> curr, vector<int> isVisited, vector<int>& nums) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!isVisited[i]) {
                curr.push_back(nums[i]);
                isVisited[i] = 1;
                DFS(res, curr, isVisited, nums);
                curr.pop_back();
                isVisited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> curr;
        vector<int> isVisited(nums.size(), 0);
        DFS(res, curr, isVisited, nums);

        return res;
    }
};
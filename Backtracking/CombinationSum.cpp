#include <vector>

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

using namespace std;

class Solution {
public:
    void Backtracking(vector<vector<int>>& res, vector<int> curr, vector<int>& candidates, int init, int sum, int target) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }
        else if (sum > target) return;
        for (int i = init; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            Backtracking(res, curr, candidates, i, sum + candidates[i], target);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        Backtracking(res, curr, candidates, 0, 0, target);
        return res;
    }
};
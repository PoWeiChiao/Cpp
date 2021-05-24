#include <vector>

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        else if (nums.size() == 2) return nums[0] >= nums[1] ? nums[0] : nums[1];
        else if (nums.size() == 3) return nums[0] + nums[2] >= nums[1] ? nums[0] + nums[2] : nums[1];
        
        vector<int> dp = nums;
        dp[2] = dp[2] + dp[0];
        int max = dp[2];
        for (int i = 3; i < nums.size(); ++i) {
            if (dp[i - 3] >= dp[i - 2]) dp[i] = dp[i] + dp[i - 3];
            else dp[i] = dp[i] + dp[i - 2];
            if (dp[i] > max) max = dp[i];
        }
        return max;
    }
};
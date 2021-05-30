#include <vector>

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(2);
        for (int i = 2; i < n; ++i) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp.back();
    }
};
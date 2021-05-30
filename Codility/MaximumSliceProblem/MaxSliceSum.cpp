#include <vector>

using namespace std;

int solution(vector<int> &A) {
    vector<int> dp(A.size(), 0);
    int ans = A.front();
    dp[0] = A.front();
    for (int i = 1; i < (int)A.size(); ++i) {
        dp[i] = A[i] + dp[i - 1] > A[i] ? A[i] + dp[i - 1] : A[i];
        if (dp[i] > ans) ans = dp[i];
    }
    return ans;
}
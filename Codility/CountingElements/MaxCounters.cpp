#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    vector<int> ans(N, 0);
    int max = 0;
    int lastMax = 0;
    for (auto &num : A) {
        if (num <= N) {
            if (ans[num - 1] < lastMax) ans[num - 1] = lastMax + 1;
            else ans[num - 1]++;
            max = max > ans[num - 1] ? max : ans[num - 1];
        }
        else lastMax = max;
    }
    for (int i = 0; i < N; ++i) {
        if (ans[i] < lastMax) ans[i] = lastMax;
    }
    return ans;
}
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int ans = 0;
    int zero_count = 0;
    for (auto &num : A) {
        if (num == 0) zero_count++;
        else {
            ans += zero_count;
            if (ans > 1000000000) return -1;
        }
    }
    return ans;
}

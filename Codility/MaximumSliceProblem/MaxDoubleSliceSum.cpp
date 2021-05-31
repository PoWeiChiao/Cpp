#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    vector<int> front(A.size(), 0);
    vector<int> back(A.size(), 0);


    for (int i = 1; i < (int)A.size() - 1; ++i) {
        front[i] = max(front[i - 1] + A[i], 0);
    }

    for (int i = (int)A.size() - 2; i > 0; --i) {
        back[i] = max(back[i + 1] + A[i], 0);
    }

    int ans = 0;
    for (int i = 1; i < (int)A.size() - 1; ++i) {
        ans = max(ans, front[i - 1] + back[i + 1]);
    }
    return ans;
}

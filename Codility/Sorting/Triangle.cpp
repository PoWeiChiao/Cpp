#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;
    sort(A.begin(), A.end());

    for (int i = (int)A.size() - 1; i >= 2; --i) {
        if (A[i] - A[i - 2] < A[i - 1]) return 1;
    }
    return 0;
}
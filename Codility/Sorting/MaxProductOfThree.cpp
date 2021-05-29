#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int index = A.size() - 1;
    if (A.front() > 0 || A.back() < 0) {
        return A[index] * A[index - 1] * A[index - 2];
    }
    return A[0] * A[1] * A[index] > A[index] * A[index - 1] * A[index - 2] ? A[0] * A[1] * A[index] : A[index] * A[index - 1] * A[index - 2];
}
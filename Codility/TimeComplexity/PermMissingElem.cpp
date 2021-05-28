#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int i = 0;
    while (i < (int)A.size()) {
        if (A[i] != i + 1) return i + 1;
        i++;
    }
    return A.size() + 1;
}
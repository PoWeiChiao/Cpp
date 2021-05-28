#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    if (A.empty()) return A;
    K = K % A.size();
    if (K == 0) return A;
    int count = A.size();
    int i = 0;
    while (count > 0) {
        int prev = A[i];
        int index = i;
        while (true) {
            index = (index + K) % A.size();
            int temp = A[index];
            A[index] = prev;
            prev = temp;
            count--;
            if (index == i) break;
        }
        i++;
    }
    return A;
}
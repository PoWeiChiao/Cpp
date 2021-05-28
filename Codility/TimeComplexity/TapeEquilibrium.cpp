#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    if (A.size() == 2) return abs(A.front() - A.back());
    int sum = 0;
    for (auto &num : A) sum += num;
    int min = 2147483647;
    int count = 0;
    for (int i = 0; i < A.size() - 1; ++i) {
        count += A[i];
         int temp = abs(count - (sum - count));
        if (temp < min) { 
            min = temp; 
            if (min == 0) break;
        }
    }
    return min;
}
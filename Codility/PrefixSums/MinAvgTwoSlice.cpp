#include <vector>

using namespace std;

int solution(vector<int> &A) {
    float min = 2147483647.0;
    int minIndex = 0;
    for (int i = 0; i < (int)A.size() - 1; ++i) {
        int sum = A[i];
        int count = 1;
        for (int j = i + 1; j < (int)A.size(); ++j) {
            sum += A[j];
            count++;
            float avg = (float)sum / (float)count;
            if (avg < min) {
                min = avg;
                minIndex = i;
            }
            if (count == 3) break;
        }
    }
    return minIndex;
}
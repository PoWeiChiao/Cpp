#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    if ((int)A.size() < 2) return 0;
    else if ((int)A.size() == 2) 
        return A.back() > A.front() ? A.back() - A.front() : 0;
    
    int min = A.front();
    int profit = 0;
    for (int i = 1; i < (int)A.size(); ++i) {
        min = A[i] < min ? A[i] : min;
        profit = profit > A[i] - min ? profit : A[i] - min;
    }
    return profit;
}
#include <math.h>

using namespace std;

int solution(int N) {
    if (N < 3) return N;
    int sq = sqrt(N);
    int i = 1;
    int count = 0;
    while (sq >= i) 
    {   
        if (N % i == 0) {
            if (N / i != i) count += 2;
            else if (N / i == i) count += 1;
        }
        i++;
    }
    return count;
}
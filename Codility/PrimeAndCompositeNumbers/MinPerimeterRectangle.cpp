#include <math.h>

using namespace std;

int solution(int N) {
    if (N == 1) return 4;
    if (N == 2) return 6;
    int sq = (int)sqrt(N);
    int ans = (N + 1) * 2;
    int i = 2;
    while (sq >= i) {
        if (N % i == 0) ans = min((N / i + i) * 2, ans);
        i++;
    }
    return ans;
}

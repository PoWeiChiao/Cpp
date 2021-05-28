int solution(int A, int B, int K) {
    if (A == 0 && B == 0) return 1;
    if (K > B) return 0;
    int start = A;
    int end = B;
    while (true) {
        if (start % K == 0) break;
        start++;
    }
    while (true) {
        if (end % K == 0) break;
        end--;
    }
    return start == end ? 1 : (end - start) / K + 1;
}
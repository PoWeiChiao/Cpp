#include <vector>
#include <unordered_map>

using namespace std;

int solution(int X, vector<int> &A) {
    int time = -1;
    
    unordered_map<int, int> m;
    int count = X;
    for (int i = 0; i < (int)A.size(); ++i) {
        if (m.find(A[i]) == m.end()) {
            m[A[i]]++;
            count--;
            if (count == 0) return i;
        }
    }
    return time;
}
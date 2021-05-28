#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, int> m;
    int max = 0;
    for (auto &num : A) {
        if (m.find(num) == m.end()) {
            m[num]++;
            if (num > max) max = num;
        }
    }
    if (max == 0) return 1;
    for (int i = 1; i <= max; ++i) {
        if (m.find(i) == m.end()) return i;
    }
    return max + 1;
}
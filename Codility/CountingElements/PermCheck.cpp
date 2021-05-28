#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, int> m;
    for (auto &num : A) m[num]++;
    for (int i = 1; i <= (int)A.size(); ++i) {
        if (m.find(i) != m.end() && m[i] != 1) return 0;
        else if (m.find(i) == m.end()) return 0;
    }
    return 1;
}
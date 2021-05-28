#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, int> m;
    for (auto &num : A) {
        if (m.find(num) != m.end()) {
            m.erase(num);
        }
        else m[num]++;
    }
    for (auto &it : m) return it.first;
    return 0;
}
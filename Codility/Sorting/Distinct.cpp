#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, int> m;
    for (auto &num : A) m[num]++;
    int count = 0;
    for (auto &it : m) count++;
    return count;
}
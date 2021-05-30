#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < (int)A.size(); ++i) {
        if (m.find(A[i]) == m.end()) {
            vector<int> vec;
            vec.push_back(i);
            vec.push_back(1);
            m[A[i]] = vec;
        }
        else {
            m[A[i]][1]++;
        }
    }
    for (auto &it : m) {
        if (it.second[1] > (int)(A.size() / 2)) return it.second[0];
    }
    return -1;
}
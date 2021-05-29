#include <string>
#include <vector>

using namespace std;

int solution(string &S) {
    if (S.empty()) return 1;
    vector<char> vec;
    for (auto &c : S) {
        if (c == ')') {
            if (!vec.empty() && vec.back() == '(') vec.pop_back();
            else return 0;
        }   
        else if (c == '}') {
            if (!vec.empty() && vec.back() == '{') vec.pop_back();
            else return 0;
        }
        else if (c == ']') {
            if (!vec.empty() && vec.back() == '[') vec.pop_back();
            else return 0;
        }
        else vec.push_back(c);
    }
    return vec.empty() ? 1 : 0;
}
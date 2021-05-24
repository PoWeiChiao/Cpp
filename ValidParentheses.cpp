#include <string>
#include <vector>

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        for (auto &c : s) {
            if (c == ')') {
                if (!vec.empty() && vec.back() == '(') vec.pop_back();
                else return false;
            }
            else if (c == '}') {
                if (!vec.empty() && vec.back() == '{') vec.pop_back();
                else return false;
            }
            else if (c == ']') {
                if (!vec.empty() && vec.back() == '[') vec.pop_back();
                else return false;
            }
            else vec.push_back(c);
        }
        return vec.empty();
    }
};
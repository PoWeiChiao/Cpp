#include <vector>

// Given a balanced parentheses string s, compute the score of the string based on the following rule:

// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> vec;
        vec.push_back(0);
        for (auto &c : s) {
            if (c == '(') vec.push_back(0);
            else {
                int i = vec.back();
                vec.pop_back();
                int j = vec.back();
                vec.pop_back();
                vec.push_back(j + max(2 * i, 1));
            }
        }
        return vec.back();
    }
};
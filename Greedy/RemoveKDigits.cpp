#include <string>
#include <vector>

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        for (int i = 0; i < num.size(); ++i) {
            if (stack.empty()) stack.push_back(num[i]);
            else {
                while (!stack.empty() && k > 0 && stack.back() > num[i]) {
                    k--;
                    stack.pop_back();
                }
                stack.push_back(num[i]);
            }
        }
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }
        string ans;
        bool leading_zero = true;
        for (auto &it : stack) {
            if (leading_zero) {
                if (it != '0') {
                    leading_zero = false;
                    ans.push_back(it);
                }
            }
            else ans.push_back(it);
        }
        return ans.empty() ? "0" : ans; 
    }
};
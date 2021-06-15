#include <vector>

// Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;
        int j = 0;
        for (auto &it : pushed) {
            stack.push_back(it);
            while (!stack.empty() && j < popped.size() && popped[j] == stack.back()) {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};
#include <string>
#include <vector>

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs.front();
        string res;
        int idx = 0;
        while (true) {
            if (strs.front().size() == idx) break;
            for (auto &s : strs) {
                if (s.size() == idx || s[idx] != strs.front()[idx]) return res;
            }
            res.push_back(strs.front()[idx]);
            idx++;
        }
        return res;
    }
};
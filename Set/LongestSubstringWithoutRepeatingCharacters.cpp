#include <string>
#include <unordered_set>

// Given a string s, find the length of the longest substring without repeating characters.

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int i = 0;
        int j = 0;
        int mx = 0;
        unordered_set<char> ms;

        while (j < s.size()) {
            if (ms.find(s[j]) == ms.end()) {
                ms.insert(s[j]);
                j++;
                mx = max(mx, (int)ms.size());
            }
            else {
                ms.erase(s[i]);
                i++;
            }
        }
        return mx;
    }
};
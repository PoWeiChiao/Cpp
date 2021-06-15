#include <string>
#include <unordered_map>

// A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) m[s[i]] = i;
        int start = 0;
        int last = 0;
        for (int i = 0; i < s.size(); ++i) {
            last = max(last, m[s[i]]);
            if (i == last) {
                ans.push_back(last - start + 1);
                start = last + 1;
            }
        }
        return ans;
    }
};
#include <string>

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        while (s.size() > 0) {
            s.erase(s.find_last_not_of(' ') + 1);
            bool found = false;
            for (int i = s.size() - 1; i >= 0; --i) {
                if (s[i] == ' ') {
                    res.append(s.substr(i + 1, s.size() - i));
                    s.erase(i + 1, s.size() - i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                res.append(s);
                break;
            }
            res.push_back(' ');
        }
        res.erase(res.find_last_not_of(' ') + 1);
        return res;
    }
};
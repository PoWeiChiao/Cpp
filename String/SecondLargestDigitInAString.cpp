#include <string>
#include <vector>

// Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
// An alphanumeric string is a string consisting of lowercase English letters and digits.

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        vector<int> nums(10, 0);
        for (auto &c : s) {
            switch (c) {
            case '0':
                nums[0]++;
                break;
            case '1':
                nums[1]++;
                break;
            case '2':
                nums[2]++;
                break;
            case '3':
                nums[3]++;
                break;
            case '4':
                nums[4]++;
                break;
            case '5':
                nums[5]++;
                break;
            case '6':
                nums[6]++;
                break;
            case '7':
                nums[7]++;
                break;
            case '8':
                nums[8]++;
                break;
            case '9':
                nums[9]++;
                break;
            }
        }
        bool found = false;
        for (int i = 9; i >= 0; --i) {
            if (nums[i] != 0) {
                if (found) return i;
                else found = true;
            }
        }
        return -1;
    }
};
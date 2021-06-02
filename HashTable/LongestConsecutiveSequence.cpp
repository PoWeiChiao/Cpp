#include <vector>
#include <map>

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        int ans = 1;
        int temp = m.begin()->first;
        int count = 1;
        for (auto &it : m) {
            if (it.first != temp) {
                if (it.first - temp == 1) {
                    count++;
                    ans = max(ans, count);
                }
                else count = 1;
                temp = it.first;
            }
        }
        return ans;
    }
};
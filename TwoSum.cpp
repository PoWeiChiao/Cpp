#include <vector>
#include <unordered_map>

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                res.push_back(m[target - nums[i]]);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
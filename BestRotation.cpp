#include <vector>

// Given an array nums, we may rotate it by a non-negative integer k so that the array becomes nums[k], nums[k+1], nums[k+2], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1].  Afterward, any entries that are less than or equal to their index are worth 1 point.
// For example, if we have [2, 4, 1, 3, 0], and we rotate by k = 2, it becomes [1, 3, 0, 2, 4]. This is worth 3 points because 1 > 0 [no points], 3 > 1 [no points], 0 <= 2 [one point], 2 <= 3 [one point], 4 <= 4 [one point].
// Over all possible rotations, return the rotation index k that corresponds to the highest score we could receive. If there are multiple answers, return the smallest such index k.

using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int k = 0;
        int max_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[(i + j) % nums.size()] <= j) count++;
            }
            if (count > max_count) {
                max_count = count;
                k = i;
            }
        }
        return k;
    }
};
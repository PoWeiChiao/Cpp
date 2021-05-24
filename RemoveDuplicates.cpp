#include <vector>

// Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int count = 1;
        int prev = 0;
        int curr = 1;
        while (curr < nums.size()) {
            if (nums[prev] == nums[curr]) curr++;
            else {
                swap(nums, prev + 1, curr);
                prev++;
                curr++;
                count++;
            }
        }
        return count;
    }
};
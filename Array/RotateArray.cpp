#include <vector>

// Given an array, rotate the array to the right by k steps, where k is non-negative.

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        int i = 0, 
        int count = 0;
        while (count < nums.size()) {
            int current = i;
            int prev = nums[i];
            while (true) {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
                if (current == i) break;
            }
            i++;
        }
    }
};
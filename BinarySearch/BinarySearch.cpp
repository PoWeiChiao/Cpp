#include <iostream>
#include <vector>

using namespace std;

bool BinarySearch(vector<int>& nums, int target) {
    if (target < nums.front()) return false;
    if (target > nums.back()) return false;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) high = mid - 1;
        else if (nums[mid] < target) low = mid + 1;
    }
    return false;
}

int main() {
    vector<int> nums;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 != 0) nums.push_back(i);
    }
    bool exist = BinarySearch(nums, 2);
    cout << exist << endl;
    return 0;
}
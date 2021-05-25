#include <vector>

// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};

        vector<vector<int>> res;
        int i = 0;
        while (i < intervals.size() && intervals[i].back() < newInterval.front()) {
            res.push_back(intervals[i]);
            i++;
        }
        int minimum = i < intervals.size() ? min(intervals[i].front(), newInterval.front()) : newInterval.front();

        while (i < intervals.size() && intervals[i].front() <= newInterval.back()) i++;

        int maximum = i > 0 ? max(intervals[i - 1].back(), newInterval.back()) : newInterval.back();
        res.push_back({minimum, maximum});

        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
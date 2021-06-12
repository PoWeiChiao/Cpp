#include <cmath>
#include <vector>
#include <map>

// We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 
// Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 
// Every worker can be assigned at most one job, but one job can be completed multiple times.
// For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.
// What is the most profit we can make?

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int ,int> m;
        int diff_max = 0;
        for (int i = 0; i < profit.size(); ++i) {
            m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
            diff_max = max(diff_max, difficulty[i]);
        }
        vector<int> vec(diff_max + 1, 0);
        int best = 0;
        bool first = true;
        int previous = 0;
        for (auto &it : m) {
            if (first) {
                best = max(best, it.second);
                previous = it.first;
                first = false;
            }
            else {
                for (int i = previous; i < it.first; ++i) vec[i] = best;
                previous = it.first;
                best = max(best, it.second);
            }
        }
        for (int i = previous; i < vec.size(); ++i) vec[i] = best;
        int ans = 0;
        for (auto &w : worker) {
            ans += w >= vec.size() ? vec.back() : vec[w];
        }
        return ans;
    }
};
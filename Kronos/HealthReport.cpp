#include <vector>
#include <map>

using namespace std;

class HealthReport {

map<int, int> current;
public:
    HealthReport();
    ~HealthReport();
    vector<pair<int, int>> update(vector<pair<int, int>> record) {
        unordered_map<int, int> cur;
        vector<pair<int, int>> vec;
        for (auto &it : record) cur[it.first] = it.second;
        for (auto &it : current) {
            cur[it.first] -= it.second;
            vec.push_back(make_pair(it.first, cur[it.first]));
        }
        return vec;
    }

    vector<int> maxThree() {
        vector<int> ans;
        int count = map.size() - 3;
        int i = 0;
        for (auto &it : current) {
            if (i >= count) ans.push_back(it.first);
            i++;
        }
        return ans;
    }
};
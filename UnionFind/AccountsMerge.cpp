#include <string>
#include <vector>
#include <unordered_map>

// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

using namespace std;

class Solution {
class DSU {
private:
    vector<int> vec;
public:
    DSU(int n) {
        for (int i = 0; i < n; ++i) vec.push_back(i);
    };

    int Find(int n) {
        if (n != vec[n]) vec[n] = Find(vec[n]);
        return vec[n];
    };

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            if (x < y) vec[y] = x;
            else vec[x] = y;
        }
    };
};

public:
    vector<vector<string>> helper(vector<vector<string>> accounts) {
        
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<vector<string>> m;
        for (auto &it : accounts) {
            m[it.front].push_back(it));
        }
        vector<vector<string>> ans;
        for (auto &it : m) {
            ans.push_back(helper(it.second));
        }
        return ans;
    }
};
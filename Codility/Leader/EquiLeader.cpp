#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    if ((int)A.size() < 2) return 0;
    if ((int)A.size() == 2) return A.front() == A.back() ? 1 : 0;
    unordered_map<int, int> m_front;
    unordered_map<int, int> m_back;
    vector<int> lead_front;
    vector<int> lead_back;
    int max_count = 0;
    int lead = 0;
    for (int i = 0; i < (int)A.size() - 1; ++i) {
        m_front[A[i]]++;
        if (m_front[A[i]] > max_count) {
            max_count = m_front[A[i]];
            lead = A[i];
            if (max_count > (int)(lead_front.size() + 1) / 2)
                lead_front.push_back(A[i]);
            else lead_front.push_back(-1);
        } else if (max_count > (int)(lead_front.size() + 1) / 2) {
            lead_front.push_back(lead);
        }
        else lead_front.push_back(-1);
    }
    max_count = 0;
    lead = 0;
    for (int i = (int)A.size() - 1; i > 0; --i) {
        m_back[A[i]]++;
        if (m_back[A[i]] > max_count) {
            max_count = m_back[A[i]];
            lead = A[i];
            if (max_count > (int)(lead_back.size() + 1) / 2)
                lead_back.push_back(A[i]);
            else lead_back.push_back(-1);
        } else if (max_count > (int)(lead_back.size() + 1) / 2) {
            lead_back.push_back(lead);
        }
        else lead_back.push_back(-1);
    }
    int ans = 0;
    for (int i = 0; i < (int)lead_front.size(); ++i) {
        if (lead_front[i] == -1 || lead_back[lead_back.size() - 1 - i] == -1) continue;
        if (lead_front[i] == lead_back[lead_back.size() - 1 - i]) ans++;
    }
    return ans;
}
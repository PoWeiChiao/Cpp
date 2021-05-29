#include <vector>

using namespace std;

int solution(vector<int> &H) {
    vector<int> vec;
    int current = 0;
    int block = 0;
    for (auto &h : H) {
        if (vec.empty()) {
            vec.push_back(h);
            block++;
            current = h;
        }
        else {
            if (h > current) {
                vec.push_back(h - current);
                block++;
                current = h;
            }
            else if (h < current) {
                while (!vec.empty() && current > h) {
                    current -= vec.back();
                    vec.pop_back();
                }
                if (vec.empty()) {
                    vec.push_back(h);
                    block++;
                    current = h;
                }
                else {
                    if (current != h) {
                        vec.push_back(h - current);
                        block++;
                        current = h;
                    }
                }
            }
        }
    }
    return block;
}
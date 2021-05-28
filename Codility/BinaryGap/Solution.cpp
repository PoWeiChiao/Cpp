#include <bitset>
#include <string>

using namespace std;

int solution(int N) {
    int max = 0;
    string str = bitset<32>(N).to_string();
    str = str.substr(str.find_first_of('1'));
    bool flag = false;
    int count = 0;
    for (auto &c : str) {
        if (!flag && c == '0') {
            count = 1;
            flag = true;
        } else if (flag && c == '0') {
            count++;
        } else if (c == '1') {
            if (count > max) max = count;
            count = 0;
            flag = false;
        }
    }
    return max;
}
#include <vector>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int n = S.length();
    vector<vector<int> > vACGT(4, vector<int>(1,0));
    int count[4] = {0,0,0,0};
    for(int i = 0; i < n; i++){
        switch(S[i]){
        case 'A':
            count[0] += 1;
            break;
        case 'C':
            count[1] += 1;
            break;
        case 'G':
            count[2] += 1;
            break;
        case 'T':
            count[3] += 1;
            break;
        }
        for(int k = 0; k < 4; k++){
            vACGT[k].push_back(count[k]);
        }
    }
    
    vector<int> vres;
    for(int i = 0; i < (int)P.size(); i++){
        for(int k = 0; k < 4; k++){
            if(vACGT[k][Q[i]+1]-vACGT[k][P[i]] > 0){
                vres.push_back(k+1);
                break;
            }
        }
    }
    return vres;
}
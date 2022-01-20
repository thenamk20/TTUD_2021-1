#include <bits/stdc++.h>

using namespace std;

const int N = 2000001;
int n;

vector<pair<int, int>> ped;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int iMem[N];

void init(){

    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n;
    int s, t;
    for(int i=0; i<n; i++){
        cin >> s >> t;
        ped.push_back({s, t});
    }
    sort(ped.begin(), ped.end(), compare);

    for(int i=0; i<n; i++){
        iMem[i] = -1;
    }

}

int maxAmount(int i){

    if(i >= n) return 0;

    if(iMem[i] != -1) return iMem[i];

    int res = -1000;

    int flag = 0;
    int L1 = -1;

    for(int j=i+1; j<n; j++){
        if(ped[j].first > ped[i].second){
            flag = 1;
            L1 = j;
            break;
        }
    }

    if(flag){

        int L2 = L1;

        for(int j=L1+1; j<n; j++){
            if(ped[j].first > ped[L1].second){
                L2 = j;
                break;
            }
        }

        for(int j = L1; j<=L2; j++){
            if(ped[j].first > ped[i].second){
                res = max(res, (ped[i].second - ped[i].first) + maxAmount(j));
            }
        }

        for(int j = i+1; j<L1; j++){
            if(ped[j].first <= ped[i].second){
                res = max(res, maxAmount(j));
            }
        }
    }

    else{
        res = max(res, ped[i].second - ped[i].first);
    }

    iMem[i] = res;
    // cout << "[" << i <<"] = " << res << endl;

    return res;
}

int ans(){
    int res = -1;
    for(int i=0; i<n; i++){
        res = max(res, iMem[i]);
    }
    return res;
}

int main(){

    init();
    int c = maxAmount(0);
    cout << ans() << endl;

    return 0;
}
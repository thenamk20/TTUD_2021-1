#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;

int n, x;
int D[11];
int iMem[11][1000];

void init(){

    memset(iMem, -1, sizeof(iMem));
    cin >> n >> x;
    for(int i=1; i<=n; i++){
        cin >> D[i];
    }

}

int minCoin(int i, int x){

    if(x < 0) return INF;
    if(x == 0) return 0;
    if(i == 0) return INF;

    if(iMem[i][x] != -1) return iMem[i][x];

    int res = INF;

    res = min(res, 1 + minCoin(i, x - D[i]));
    res = min(res, minCoin(i - 1 , x));


    iMem[i][x] = res; 
    // cout  << "[" << i <<"]["<< x <<"] = " << res << endl;
    return res;
}

int main(){

    init();
    cout << minCoin(n, x);

    return 0;
}
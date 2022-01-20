#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int INF = 10000000;
int n, L1, L2;
int A[N];
int iMem[N];

void init(){
    memset(iMem, -1, sizeof(iMem));
    cin >> n >> L1 >>  L2;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
}

int maxGold(int i){
    if(i > n) return 0;

    if(iMem[i] != -1) return iMem[i];
    
    int res = -1;

    for(int j=1; j<L1; j++){
        res = max(res, maxGold(i+j));
    }

    for(int j = L1 ; j <= L2; j++){
        res = max(res, A[i] + maxGold(i+j));
    } 

    iMem[i] = res;
    // cout << "[" <<i<<"] = " << res << endl;

    return res;
}

int ans(){
    int ans = -1;

    for(int i=1; i<=n; i++){
        ans = max(ans, iMem[i]);
    }
    return ans;
}

int main(){

    init();
    int b = maxGold(1);
    int res = ans();
    cout << res;

    return 0;
}
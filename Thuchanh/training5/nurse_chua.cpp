#include <bits/stdc++.h>

using namespace std;

const int N = 1003, K = 403;

int n, k1, k2, f[1004];

void init(){
    cin >> n >> k1 >> k2;
}

void solve(){
    f[0] = 1;
    for(int i=k1; i <= k2; i++){
        f[i] = 1;
    }
    for(int i=k1+1; i<=n; i++){
        for(int j=i-k1-1; j>= i-k2-1; j--){
            if(j >= 0 && f[j] !=0 ){
                f[i] = (f[i] + f[j])%1000000007;
            }
        }
    }
    cout << f[n] + f[n-1] << endl;
}


int main(){

    init();
    solve();

    return 0;
}
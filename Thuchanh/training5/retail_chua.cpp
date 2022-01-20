#include <bits/stdc++.h>

using namespace std;

int n, m, f[103][503];

int a[103];

void init(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
}

void solve(){
    f[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=a[i]; j<=m; j++){
            for(int k=j-a[i]; k>=0; k-=a[i]){
                (f[i][j] += f[i-1][k])%=1000000009;
            }
        }
    }
    cout << f[n][m];
}

int main(){

    init();
    solve();

    return 0;
}
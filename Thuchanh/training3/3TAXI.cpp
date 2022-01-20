#include <bits/stdc++.h>

using namespace std;

const int N = 12;
int f = 0, f0 = INT_MAX; // ham muc tieu

int dis[2*N+1][2*N+1];
int trav[N]; // thanh pho dich cua lan di chuyen thu k
int n; //
int dmin = INT_MAX;
int dbackmin = INT_MAX;
int isCame[N] = {0};

void init(){

    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> dis[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=n+1; j<= 2*n; j++){
            if(dis[i][j] < dmin) dmin = dis[i][j];
        }
    }

    for(int i=n+1; i<=2*n; i++){
        if(dis[0][i] < dbackmin) dbackmin = dis[0][i];
    }
}

void TRY(int k){

    for(int i=1; i<=n; i++){
        if(!isCame[i]){
            if(k==1){
                trav[1] = i+n;
                f = dis[0][i] + dis[i][i+n];
                isCame[i] = 1;
                TRY(k+1);
                isCame[i] = 0;
                f = 0;
            }
            else{
                f = f + dis[trav[k-1]][i] + dis[i][i+n]; 
                trav[k] = i+n;
                isCame[i] = 1;

                if(k==n){
                    if(f + dis[trav[k]][0] < f0) {
                        f0 = f + dis[trav[k]][0];
                    }
                    
                }
                
                else{
                    int g = f + 2*(n-k)*dmin + dbackmin;
                    if(g < f0){
                        TRY(k+1);
                    } 
                }

                isCame[i] = 0;
                f = f - dis[trav[k-1]][i] - dis[i][i+n];
            }
        }
    }
}

int main(){

    cin >> n;

    init();

    TRY(1);

    cout << f0;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 12;
int f = 0, f0 = INT_MAX; // ham muc tieu

int dis[2*N+1][2*N+1];
int n,q;
int t; // so hanh khach toi da
int dmin = INT_MAX;
int load = q; 
int isCame[2*N+1] = {0};
int trav[2*N+1];

void init(){

    trav[0] = 0;

    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> dis[i][j];
            if(i!= j && dis[i][j] < dmin){
                dmin = dis[i][j];
            } 
        }
    }

}

bool check(int i,int k){
    if(isCame[i]) return false;

    if(i <= n){
        if(load>=q) return false;
    }
    else{
        if(!isCame[i-n]) return false;
    }
    return true;
}

void TRY(int k){
    for(int i=1; i<= 2*n; i++){
        if(check(i, k)){
            f +=  dis[trav[k-1]][i];
            isCame[i] = 1;
            trav[k] = i;
            if(i <= n) load +=1; else load -= 1;

            if(k==2*n){
                if(f + dis[i][0] < f0) f0 = f + dis[i][0];
            }   
            else{
                int g = f + dmin * (2*n-k+1);
                if(g < f0){
                    TRY(k+1);
                }
            }

            f -= dis[trav[k-1]][i];
            if(i<=n) load-=1; else load += 1;
            isCame[i] = 0;

        }
    }
}


int main(){

    cin >> n >> q;

    init();

    TRY(1);

    cout << f0;

    return 0;
}
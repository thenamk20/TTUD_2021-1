#include <bits/stdc++.h>

using namespace std;

const int N = 21;

int cost[N][N] = {0};

int isVisited[N] = {0}; 

int f0 = INT_MAX; // ki luc
int cmin = INT_MAX; //

int jour[N]; // cac thanh pho da di qua


int f = 0;

void init(){

    jour[1] = 1;
    isVisited[1] = 1;
}

int n, m;

void TRY(int k){
    for(int i=2; i<=n; i++){
        if(!isVisited[i] && cost[jour[k-1]][i]){
            jour[k] = i;
            isVisited[i] = 1;
            f = f + cost[jour[k-1]][i]; 

            if(k==n && cost[i][1]){
                if(f + cost[i][1] < f0){
                    f0 = f + cost[i][1];
                }
            }
            else{
                int g = f + cmin*(n-k+1);
                if(g < f0) {
                    TRY(k+1);   
                }
            }
            
             f =  f - cost[jour[k-1]][i]; 
             isVisited[i] = 0;
        }
    }
}

int main(){
    
    cin >> n >> m;

    int a, b, c;

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
        if(cmin > c){
            cmin = c;
        }
    }

    init();
    TRY(2);
    cout << f0;
    return 0; //
}
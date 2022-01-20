// Tìm số thành phần liên thông đồ thị vô hướng

#include <bits/stdc++.h>

using namespace std;

const int N = 101;
vector<int> Adj[N];
vector<int> iComponent(N, -1); 
int n, e;

void Find_component(int cur_comp,int u){
    if(iComponent[u] == -1) return;

    iComponent[u] = cur_comp;

    for(int i=0; i< Adj[u].size(); i++){
        int v = Adj[u][i];
        Find_component(cur_comp, v);
    }
}

void init(){
    int a, b;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
    }
}


int main(){
    
    init();

    int numComp = 0;

    for(int u = 1; u<=n ; u++){
        if(iComponent[u] == -1){
            Find_component(numComp, u);
            numComp ++;
        }
    }
    cout << numComp;

    return 0;
}
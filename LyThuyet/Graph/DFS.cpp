#include <bits/stdc++.h>

using namespace std;

const int N = 101;  // tập đỉnh

vector<int> Adj[N]; // danh sách cạnh

vector<bool> bVisited(N, false);
vector<bool> bMarked(N, false);

void DFS(int u){
    if(bMarked[u])
        return;
    bMarked[u] = true;
    bVisited[u] = true;
    for(int i = 0; i< Adj[u].size(); i++){
        int v = Adj[u][i];
        bVisited[v] = true;
        DFS(v);
    }
}

int main(){


    return 0;
}
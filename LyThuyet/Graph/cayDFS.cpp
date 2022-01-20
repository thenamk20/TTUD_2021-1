#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int n; // so dinh
int e; // so canh
vector<int> Adj[N];
vector<int> Low(N), Num(N ,-1);
int curNum = 0;

void init(){
    int a,b;
    cin >> n >> e;
    // e: do thi co huong, 2*e: do thi vo huong
    for(int i=0; i<e; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
    }
}

void AnalyzeDFS(int u, int p){
    Low[u] = Num[u] = ++curNum;
    for(int i=0; i < Adj[u].size(); ++i){
        int v = Adj[u][i];
        if(v == p) continue;
        if(Num[v] == -1){
            AnalyzeDFS(v, u);
            Low[u] = min(Low[u], Low[v]);
        }else {
            Low[u] = min(Low[u], Num[v]);
        }
    }
} 

int main(){

    init();
    for(int u=1; u<=n; u++){
        if(Num[u] == -1){
            AnalyzeDFS(u, -1);
        }
    }

    for(int u=1; u<= n; u++){
        cout << Num[u] << " ";
    }

    cout << endl;
    for(int u=1; u<= n; u++){
        cout << Low[u] << " ";
    }

    return 0;
}

/* 
11 14
1 2 
1 3
2 1
2 3
3 1
3 2
3 4
4 3
4 6
4 9
5 6
5 8
5 11
6 4
6 5
6 7
6 9
7 6
7 9
7 10
8 5
8 11
9 4
9 6
9 7
10 7
11 5
11 8

*/
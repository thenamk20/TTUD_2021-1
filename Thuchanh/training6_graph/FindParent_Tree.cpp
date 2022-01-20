#include <bits/stdc++.h>

using namespace std;

const int MAX = 100004;

vector<int> Adj[MAX];
vector<bool> bVisited(MAX, false);

int Parent[MAX];

int n;

void init(){
    cin >> n;
    int a, b;
    for(int i=1; i<=n-1; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}

void solve(int start){

    queue<int> Q;
    Q.push(start);
    bVisited[start] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < Adj[u].size(); ++i)
        {   
            int v = Adj[u][i];
            if (!bVisited[v])
            {
                Parent[v] = u;
                Q.push(v);
                bVisited[v] = true;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    init();
    solve(1);
    for(int i = 2; i<=n; i++){
        cout << Parent[i] << " ";
    }

    return 0;
}
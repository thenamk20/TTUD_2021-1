#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
vector<int> Adj[N], Low(N), Num(N, -1);
int curnum = 0;
vector<pair<int, int>> iiBridges;
int n; // so dinh 
int e; // so canh

void init() {
    int a,b;
    cin >> n >> e;
    for(int i=0; i<2*e; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
    }
}

void Find_Bridges(int u, int p)
{
    Low[u] = Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        if (v == p)
            continue;
        if (Num[v] == -1)
        {
            Find_Bridges(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
        if (Low[v] > Num[u])
            iiBridges.push_back(make_pair(u, v));
    }
}


int main()
{   
    init();
    for(int u=1; u<=n; u++){
        if(Num[u] == -1){
            Find_Bridges(u, -1);
        }
    }

    cout << iiBridges.size(); // so luong cau

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
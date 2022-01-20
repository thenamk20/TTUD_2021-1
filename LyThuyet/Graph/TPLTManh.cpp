#include <bits/stdc++.h>

using namespace std;

vector<int> Adj[100001];
vector<int> Low(100001), Num(100001, -1);
vector<bool> bConnect(100001, false);
int curnum = 0;
int n, e;

stack<int> iComp;

void init(){
    int a,b;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
    }
}

void SCC(int u)
{
    iComp.push(u);
    bConnect[u] = true;
    Low[u] = Num[u] = ++curnum;

    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        if (Num[v] == -1)
        {
            SCC(v);
            Low[u] = min(Low[u], Low[v]);
        }
        else if (bConnect[v])
        {
            Low[u] = min(Low[u], Num[v]);
        }
    }

        // in ra cac thanh phan lien thong manh
    // if (Num[u] == Low[u])
    // {
    //     cout << " TPLT : ";
    //     while (true)
    //     {
    //         int cur = iComp.top();
    //         iComp.pop();
    //         bConnect[cur] = false;
    //         cout << cur << " ";
    //         if (cur == u)
    //             break;
    //     }
    //     cout << endl;
    // }
}

int main()
{

    init();

    for (int u = 1; u <= n; ++u)
        if (Num[u] == -1)
            SCC(u);


    int icount = 0;
    for(int u=1; u<= n; u++){
        if(Num[u] == Low[u]){
            icount ++;
        }
    }
    cout << icount; // so luong cac tplt manh

    return 0;
}

/*
11 14
1 2
2 3
3 1
3 4
4 6
5 8
6 5
6 7
6 9
7 9
7 10
8 11
9 4
11 5
*/
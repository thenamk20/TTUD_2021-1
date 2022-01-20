#include <bits/stdc++.h>

// đường đi ngắn nhất từ a-> b trên đồ thị ko trọng số

using namespace std;

const int N = 101; // tập đỉnh

vector<int> Adj[N]; // danh sách cạnh

vector<bool> bVisited(N, false);
vector<int> iDist(1001, -1);
queue<int> Q;
int a, b;

void init(){

}

void BFS(int a)
{
    Q.push(a);
    iDist[a] = 0;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < Adj[u].size(); ++i)
        {
            int v = Adj[u][i];
            if (iDist[v] == -1)
            {
                Q.push(v);
                iDist[v] = 1 + iDist[u];
            }
        }
    }
}

int main()
{

    init();
    cout << iDist[b];

    return 0;
}
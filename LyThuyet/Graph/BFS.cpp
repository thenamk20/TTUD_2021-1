#include <bits/stdc++.h>

using namespace std;

const int N = 101; // tập đỉnh

vector<int> Adj[N]; // danh sách cạnh

vector<bool> bVisited(N, false);
queue<int> Q;

void BFS(int start)
{
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
                Q.push(v);
                bVisited[v] = true;
            }
        }
    }
}

int main(){

    return 0;
}
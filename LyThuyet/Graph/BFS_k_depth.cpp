#include <bits/stdc++.h>

using namespace std;

const int N = 101; // tập đỉnh

vector<int> Adj[N]; // danh sách cạnh

vector<bool> bVisited(N, false);
queue<int> Q;

int n, e;

void init(){
    cin >> n >> e;
    int a, b;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}

void BFS(int start, int k)
{
    queue<int> Q;
    int level[N];
    level[start] = 0;
    Q.push(start);
    bVisited[start] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << u << endl;

        if (level[u] < k)
        {
            // kiểm tra toàn bộ cạnh kề với u
            for (int i = 0; i < Adj[u].size(); ++i)
            {
                int v = Adj[u][i];
                if (!bVisited[v])
                {
                    Q.push(v);
                    level[v] = level[u] + 1;
                    bVisited[v] = true;
                }
            }
        }
    }
}

int main()
{
    init();
    BFS(1,3);

    return 0;
}
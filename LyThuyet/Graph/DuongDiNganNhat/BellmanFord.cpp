#include <bits/stdc++.h>

// Bellman Ford: cả trong TH đồ thị trọng số âm

using namespace std;
const int N = 101;

struct edge
{
    int u, v;
    int weight;

    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        weight = _w;
    }
};

int n, e;
vector<edge> Adj[N];
vector<int> iDist(N, INT32_MAX);

void Bellman_Ford(int n, int start)
{
    iDist[start] = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (int j = 0; j < Adj[u].size(); ++j)
            {
                int v = Adj[u][j].v;
                int w = Adj[u][j].weight;
                iDist[v] = min(iDist[v], w + iDist[u]);
            }
        }
    }
}

void init()
{
    int a, b, c;
    cin >> n >> e;
    for (int i = 0; i < 2 * e; i++)
    {
        cin >> a >> b >> c;
        Adj[a].push_back(edge(a, b, c));
    }
}

int main()
{
    init();
    Bellman_Ford(n, 1);

    // in ra đường đi ngắn nhất đến từng đỉnh
    cout << "Bellman_Ford\n";
    for (int i = 1; i <= n; i++)
    {
        cout << iDist[i] << " ";
    }

    return 0;
}

/*
7 11
1 2 7
1 4 5
2 1 7
2 3 8
2 4 9
2 5 7
3 2 8
3 5 5
4 1 5
4 2 9
4 5 15
4 6 6
5 2 7
5 3 5
5 4 15
5 6 8
5 7 9
6 4 6
6 5 8
6 7 11
7 5 9
7 6 11

*/
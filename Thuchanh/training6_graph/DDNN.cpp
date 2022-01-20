#include <bits/stdc++.h>

// Disjktra: ddnn đồ thị trọng số không âm 

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
int s,t;
vector<edge> Adj[N];
vector<int> iDist(N, INT32_MAX);

void Dijkstra(int start)
{
    iDist[start] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        PQ;
    PQ.push(make_pair(iDist[start], start));
    while (!PQ.empty())
    {
        int u = PQ.top().second;
        PQ.pop();
        for (int i = 0; i < Adj[u].size(); i++)
        {
            int v = Adj[u][i].v;
            int w = Adj[u][i].weight;
            if (w + iDist[u] < iDist[v])
            {
                iDist[v] = w + iDist[u];
                PQ.push(make_pair(iDist[v], v));
            }
        }
    }
}

void init(){
    int a, b, c;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        Adj[a].push_back(edge(a,b,c));
    }
    cin >> s >> t;
}

int main()
{
    init();
    Dijkstra(s);

    cout << iDist[t];

    return 0;
}


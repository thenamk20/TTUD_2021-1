#include <bits/stdc++.h>

// đồ thị có hướng, đường đi ngắn nhất
const int MAX = 10000000;

using namespace std;

int f, s, g, u, d;

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

vector<edge> Adj[MAX]; // danh sách cạnh 
vector<int> iDist(MAX, INT32_MAX);

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
    cin >> f >> s >> g >> u >> d;
}

void createAdj() {
    for(int i=1; i<=f; i++){
        int below = i - d;
        int above = i + u;
        if(below >= 1){
            Adj[i].push_back(edge(i, below, 1));
        } 
        if(above <= f){
            Adj[i].push_back(edge(i, above, 1));
        }
    }
}


void solve(){
    // Bellman_Ford(f, s);
    Dijkstra(s);
    int result = iDist[g];
    if(result == INT32_MAX){
        cout << "use the stairs" << endl;
    }
    else {
        cout << result << endl;
    }

    // for(int i=1; i<=f; i++){
    //     cout << Adj[i].size() << endl;
    // }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    init();
    createAdj();
    solve();

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5004, KMAX = 10004;

vector<int> Adj[NMAX]; // danh sách cạnh

int cost[NMAX];
int maxTravel[NMAX];
vector<int> iDist(NMAX, INT32_MAX);

int n, k;

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

vector<edge> newAdj[NMAX];

void BFS(int start, int k)
{   
    vector<bool> bVisited(NMAX, false);
    queue<int> Q;
    int level[NMAX];
    level[start] = 0;
    Q.push(start);
    bVisited[start] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u != start){
            newAdj[start].push_back(edge(start, u, cost[start]));
        }

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

void init(){
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> cost[i] >> maxTravel[i];
    }
    int a, b;
    for(int i=1; i<=k; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}

void createNewAdj(){

    for(int i=1; i<=n; i++){
        BFS(i, maxTravel[i]);
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
        for (int i = 0; i < newAdj[u].size(); i++)
        {
            int v = newAdj[u][i].v;
            int w = newAdj[u][i].weight;
            if (w + iDist[u] < iDist[v])
            {
                iDist[v] = w + iDist[u];
                PQ.push(make_pair(iDist[v], v));
            }
        }
    }
}

void solve(){
    Dijkstra(1);
    cout << iDist[n] << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    init();
    createNewAdj();
    solve();

    return 0;
}
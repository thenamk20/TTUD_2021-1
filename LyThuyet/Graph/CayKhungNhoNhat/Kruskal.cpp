#include <bits/stdc++.h>

using namespace std;
const int N = 100001; // số cạnh tối đa
int n;
int e;

struct Edge
{
    int u, v;
    int weight;

    Edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<Edge>Adj;

struct Union_Find
{
    vector<int> iParent;

    Union_Find(int n)
    {
        iParent = vector<int>(n);
        for (int i = 1; i <= n; i++)
        {
            iParent[i] = i;
        }
    }

    // trả về phần tử đại diện cho một tập
    int Find(int x)
    {
        if (iParent[x] == x)
        {
            return x;
        }
        else
        {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }

    // hợp nhất tập chứa x và tập chứa y
    void Unite(int x, int y)
    {
        iParent[Find(x)] = Find(y);
    }
};

bool Edge_Cmp(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

vector<Edge> MST(int n, vector<Edge> Edges)
{
    Union_Find UF(n);
    sort(Edges.begin(), Edges.end(), Edge_Cmp);
    vector<Edge> res;
    for (int i = 0; i < Edges.size(); ++i)
    {
        int u = Edges[i].u,
            v = Edges[i].v;
        if (UF.Find(u) != UF.Find(v))
        {
            UF.Unite(u, v);
            res.push_back(Edges[i]);
        }
    }
    return res;
}

void init(){
    cin >> n >> e;
    int a,b,c;
    for(int i=0; i<2*e; i++){
        cin >> a >> b >> c;
        Adj.push_back(Edge(a, b, c));
    }
}

int main()
{
    init();

    vector<Edge> a = MST(n, Adj);

    // print cay khung nho nhat
    // cout <<  "MST" << endl;
    // for(int i=0; i<a.size(); i++){
    //     cout << a[i].u <<" "<< a[i].v <<" "<< a[i].weight << endl;
    // }

    // in ra trọng số
    int res = 0;
    for(int i=0; i<a.size(); i++){
        res += a[i].weight;
    }
    cout << res;

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


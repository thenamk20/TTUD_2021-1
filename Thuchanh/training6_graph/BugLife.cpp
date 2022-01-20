#include <bits/stdc++.h>

using namespace std;

int n; // số đỉnh (số con bọ)
int m; // số cạnh (tương tác)
vector<vector<int>> vt;
int color[2004];

void init(){

    cin >> n >> m;
    vt.clear();
    vt.resize(n+1);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        color[i] = 0;
    }
}

bool solve()
{
    queue<int> q;
    q.push(1);
    color[1] = 1;
    
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int v : vt[x])
        {
            if (color[v] == 0)
            {
                if (color[x] == 1)
                {
                    color[v] = 2;
                }
                else
                {
                    color[v] = 1;
                }
                q.push(v);
            }
            else
            {
                if(color[v] == color[x]) return false;
            }
        }
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    for(int i=1; i<=t; i++){
        init();
        int res = solve();
        cout << "Scenario #" << i << ":"<< endl;
        if(res){
            cout << "No suspicious bugs found!" << endl;
        }
        else{
            cout << "Suspicious bugs found!" << endl;
        }
    }

    return 0;
}
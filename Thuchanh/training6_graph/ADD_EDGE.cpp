#include <bits/stdc++.h>

using namespace std;

const int MAX = 100004;

int n;
int m;

vector<int> Adj[MAX];

void init(){
    cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}



void solve(){

}

int main(){





    return 0;
}
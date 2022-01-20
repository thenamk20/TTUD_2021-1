#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int cost[N][N] = {0};

int main()
{

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << cost[i][j] << " " << endl;
        }
        cout << endl;
    }

  
    return 0;
}
#include <bits/stdc++.h>

using namespace std;




int main(){

    int n, m; 
    cin >> n;
    int x = 0;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        x = x | (1 << a);
    }
    int flag = 1;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a;
        if(!(x & (1<<a))) flag = 0; 
    }

    if(flag) cout << 1;
    else cout << 0;
 
    return 0;

}
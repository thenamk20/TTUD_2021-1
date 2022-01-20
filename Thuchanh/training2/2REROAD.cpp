#include <bits/stdc++.h>

using namespace std;



int main(){

    int a[100];
    int mark[100];
    int n; cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }    
    a[0] = -1;
    vector<pair<int, int>> vt;
    int k; cin >> k;

    while(k--){
        int a,b;
        cin >> a >> b;
        vt.push_back({a, b});
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        if(a[i] != a[i-1]) {
            mark[i] = 1;
            sum++;
        }
        else mark[i] = 0;
    }

    int m = vt.size();
   
    for(int i = 0; i<m; i++){
        int p = vt[i].first; // chỉ số đoạn đường
        int q = vt[i].second; // loại nhựa đường cập nhật

        if(q != a[p]){
            if(mark[p] == 0){
               if(mark[p+1] ==0) {
                   if(q != a[p+1]) sum += 2; 
               }
               else{
                   if(q != a[p+1]) sum += 1;
               }
            }
            else{
                
            }
        }

    }

    return 0;
}
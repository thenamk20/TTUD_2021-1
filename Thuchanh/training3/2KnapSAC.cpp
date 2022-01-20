#include <bits/stdc++.h>
 
using namespace std;
 
 
const int N = 31;
 
int weight[N];  // trong luong
int value[N];   // gia tri su dung
 
vector<pair<int,int>> sortItems;

int n,b;
int f0, f;   // ham muc tieu 
int isUsed[N] = {0}; 
int vMax = 0;
int wMin = INT_MIN;
 
void init(){
    f0 = -1;
    f = 0;
}

int compare(pair<int, int> a, pair<int, int> b){
    return a.second/a.first > b.second/b.first;
}

void TRY(int k){
    for(int i=1; i<=n; i++){
 
        if(!isUsed[i] && weight[i] <= b){
            isUsed[i] = 1;
 
            f = f + value[i];
            b = b - weight[i]; 
            
            int g = f + b*sortItems[k].second/sortItems[k].first;

            if(g > f0){
                TRY(k+1);  
            }    

            b = b + weight[i]; 
            f = f - value[i];
            isUsed[i] = 0; 
        }
 
        else{
            if(i==n){
                if(f > f0) f0 = f;
            }
        }
    }
}
 
int main(){
 
    cin >> n >> b; 
    int p, q;
    for(int i=1; i<=n; i++){
        cin >> p >> q;
        weight[i] = p;
        value[i] = q;
        sortItems.push_back({p,q});

        if(p < wMin) wMin = p;
        if(q > vMax) vMax = q;
        
    }


    init();
    sort(sortItems.begin(), sortItems.end(),compare);
    TRY(1);
 
    cout << f0;
 
    return 0;
}
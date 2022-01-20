#include <bits/stdc++.h>
 
using namespace std;
 
 
const int N = 31;
 
vector<int> weight;  // trong luong
vector<int> value;   // gia tri su dung
 
vector<int> sortWeight;
vector<int> sortValue; 

int n,b;
int f0, f;   // ham muc tieu 
int isUsed[N] = {0}; 
int vMax = 0;
int wMin = INT_MIN;
 
int compare(int a, int b){
    return a > b;
}

void init(){
    f0 = -1;
    f = 0;
    sortWeight.push_back(0);
    sortValue.push_back(INT_MAX);

    cin >> n >> b; 
    int p, q;
    for(int i=1; i<=n; i++){
        cin >> p >> q;
        weight.push_back(p);
        value.push_back(q);
        sortWeight.push_back(p);
        sortValue.push_back(q);

        if(p < wMin) wMin = p;
        if(q > vMax) vMax = q;
        
    }

    sort(sortWeight.begin(), sortWeight.end());
    sort(sortValue.begin(), sortValue.end(),compare);
}
 

void TRY(int k){
    for(int i=1; i<=n; i++){
 
        if(!isUsed[i] && weight[i] <= b){
            isUsed[i] = 1;
 
            f = f + value[i];
            b = b - weight[i]; 
            
            int g = f + b/sortWeight[k+1] * sortValue[k+1];

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
 
    init();
 
    TRY(1);
 
    cout << f0;
 
    return 0;
}
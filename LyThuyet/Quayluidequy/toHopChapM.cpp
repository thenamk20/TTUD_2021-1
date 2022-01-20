#include <bits/stdc++.h>

using namespace std;

int m,n;
int a[100];

void init(){
    a[0] = 0;
}

void print(int* a){
    for(int i=1; i<=m; i++){
        cout << a[i];
    }
    cout << endl;
}



void TRY(int k){

    for(int i = a[k-1] + 1; i<=n-m+k; i++){
        a[k] = i;
        if(k==m) print(a); 
        else TRY(k+1);
    }
}

int main(){

    cin >> n >> m;

    TRY(1);

    return 0;
}
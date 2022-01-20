#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];
int mark[100];

void init(){
    for(int i=1; i<=n; i++) mark[i] = 0;
}

void print(int* a){
    for(int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}

void TRY(int k){
    for(int i=1; i<=n; i++){
        if(!mark[i]){
            a[k] = i;
            mark[i] = 1;
            if(k==n) print(a);
            else TRY(k+1);
            mark[i] = 0;
        }
    }

}

int main(){

    cin >> n;

    TRY(1);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int a[100];
int n;

void print(int* a){
    for(int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}

void TRY(int k){
    for(int i=0; i<=1; i++){
        a[k] = i;
        if(k==n) print(a);
        else TRY(k+1); 
    }
}


int main(){

    cin >> n;
    TRY(1);

    return 0;

}
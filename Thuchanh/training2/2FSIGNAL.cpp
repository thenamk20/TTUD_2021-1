#include <bits/stdc++.h>

using namespace std;

void print(int* a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){

    int n, b;
    cin >> n >> b;

    int a[200000];

    for(int i=0; i<n; i++) cin >> a[i];

    int maxFromLeft[200000], maxFromRight[200000];

    maxFromLeft[0] = a[0];
    maxFromRight[n-1] = a[n-1];

    for(int i=1; i<n; i++){
        if(maxFromLeft[i-1] < a[i]) maxFromLeft[i] = a[i];
        else maxFromLeft[i] = maxFromLeft[i-1];
    }

    for(int i=n-2; i>=0; i--){
        if(maxFromRight[i+1] < a[i]) maxFromRight[i] = a[i];
        else maxFromRight[i] = maxFromRight[i+1];
    }

    //process 
    int max = -1;
    for(int i=1; i<n-1; i++){
        
        int maxLeft = maxFromLeft[i-1];
        int maxRight = maxFromRight[i+1];

        if(maxLeft - a[i] >= b && maxRight - a[i] >= b){
            int tmp = maxLeft + maxRight - 2*a[i];
            if(tmp > max) max = tmp; 
        } 
    }

    cout << max;

    return 0;
}
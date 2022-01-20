#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int A[N];
int iMem[N];
bool bMark[N];
int n;

void init(){
    memset(bMark, 0, sizeof(bMark));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
}

int maxSum(int i){

    if(i == 0) return A[i];

    if(bMark[i]) return iMem[i];

    int res = max(A[i], maxSum(i-1) + A[i]);

    iMem[i] = res;
    bMark[i] = 1;

    return res;
}


int ans(){
    int res = INT_MIN;

    for(int i=0; i<n; i++){
        res = max(res, iMem[i]);
    }
    return res;
}

int main(){

    init();
    int a = maxSum(n-1);
    cout << ans() << endl;

    return 0;
}
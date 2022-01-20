#include <bits/stdc++.h>

using namespace std;

int n;
int A[1000];
int iMem[1000];
int pos = 0;

void init(){

    memset(iMem, -1, sizeof(iMem));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

}

int LIS (int i) {

    if(iMem[i] != -1) return iMem[i];

    int res = 1;

    for(int j=0; j<i; j++){
        if(A[j] < A[i]) res = max(res, 1 + LIS(j));
    }

    iMem[i] = res;

    return res;
}

int ans() {
    int res = 1;
    for(int i=0; i<n; i++){
        res = max(res, iMem[i]);
        if(res = iMem[i]) pos = i;
    }
    return res;
}

void Trace(int i) {
    
    for(int j= i-1; j>= 0; j--){
        if(A[j] < A[i] && iMem[i] == iMem[j] + 1){
            Trace(j);
            break;
        }
    }
    cout << A[i] << " ";
}

int main(){

    init();
    int a = LIS(n-1);
    cout << ans() << endl;
    Trace(pos);

    return 0;
}
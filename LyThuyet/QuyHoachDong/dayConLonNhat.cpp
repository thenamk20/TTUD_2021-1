#include <bits/stdc++.h>

using namespace std;

int A[101];
int iMem[101];
bool bMark[101] = {0};
int n;
int pos;

void init(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
}

int maxSum(int i){

    if(i==1) return A[i];

    if(bMark[i]) return iMem[i];

    int res = max(A[i]*A[i]*A[i], maxSum(i-1) + A[i]*A[i]*A[i]);
    iMem[i] = res;
    bMark[i] = true;

    return res;
}

int result(){
    int res = INT_MIN;
    for(int i=1; i<=n; i++){
        res = max(res, iMem[i]);
        if(res == iMem[i]) pos = i;

    }
    return res;
}

// void trace(int i){

//     if(i != 1 && iMem[i] == A[i] + iMem[i-1]) {
//         trace(i-1);
//     }
//     cout << A[i] << " ";
// }


int main(){

    init();
    int maxSumN = maxSum(n);

    int ans = result();
    cout << ans << endl;

    return 0;
}

/**
7
-16 7 -3 0 -1 5 -4
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 103;
const int M = 503;
const int R = 1000000007;

int n, m; // n chi nhánh, m cửa hàng 

int A[103]; // nhân viên bán hàng mỗi nhánh

int iMem[N+1][M+1];

void init(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    memset(iMem, -1, sizeof(iMem));
}

// base case: F[0][0] = 1; 
// F(i,p) += F(i-1, p-k)
int F(int i, int p) { // số cách chia p cửa hàng bán lẻ vào i chi nhánh đầu tiên
    if(i==0 && p==0) return 1;
    if(iMem[i][p] != -1) return iMem[i][p];

    int res = 0;
    for(int j=1; j<=i; j++){
        res += F(i-1, p-A[j]);
    }
    
    iMem[i][p] = res; 
    return res;
}

int main(){

    init();
    int a = F(n,m);
    cout << a << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n, k1, k2;

const int M = 1000000009;
const int N = 1003;

int iMem[N];

void init(){

    ios::sync_with_stdio(0);
    cin.tie();
    cin >> n >> k1 >> k2;
    memset(iMem, -1, sizeof(iMem));
}

int numberPlan(int i){ // làm việc kết thúc ở ngày thứ i

    if(i==0) return 1;
    if(k1 <= i && i <= k2) return 1;

    if(iMem[i] != -1) return iMem[i];
    
    int res = 0;
    for(int j=i-k2-1; j <= i-k1-1; j++){
        
        res = res + numberPlan(i);
        
    }

    iMem[i] = res;
    return res;
}


int main(){

    init();
    int a = numberPlan(n) + numberPlan(n-1);
    cout << a << endl;

    return 0;
}
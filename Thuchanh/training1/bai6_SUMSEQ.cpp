#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

int reValue(int n){
    while(n > M){
        n -= M;
    }
    return n;
}

int main()
{
    vector<int> vt;
    int a;
    unsigned long long sum = 0;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        int tmp = reValue(a);
        vt.push_back(tmp);
        sum += tmp;
        sum = reValue(sum);

    }
    cout << sum;

    return 0;
}

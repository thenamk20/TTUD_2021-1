#include <bits/stdc++.h>

using namespace std;

int c; 
long long int x; // money

int n; // số lượng đồng tiền của currency

vector<long long int> currency;

void init(){
    cin >> x >> c;
    n = (c+1)*4;

    for(int i=0; i<=c; i++){
        int tmp = 1;
        for(int j=1; j<=i; j++){
            tmp*=10;
        }

        currency.push_back(1000*tmp);
        currency.push_back(2000*tmp);
        currency.push_back(3000*tmp);
        currency.push_back(5000*tmp);
    }
}

int moneyChange(long long int a){
    int count = 0;
    while(a > 0){
        for(int i=n-1; i>=0; i--){
            if(currency[i] <= a){
                count++;
                a = a - currency[i];
                break;
            }
        }
    }
    return count;
}


void solve(){
    cout << moneyChange(x) << " " << 1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        init();
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int currency[6] = {1,5,10,50,100,500};

int s;

int solve(int a){
    int count = 0;
    while(a > 0){
        for(int i=5; i>=0; i--){
            if(currency[i] <= a){
                count++;
                a = a - currency[i];
                break;
            }
        }
    }
    return count;
}


int main(){

    cin >> s;
    cout << solve(1000-s);

    return 0;
}
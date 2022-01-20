#include <bits/stdc++.h>

using namespace std;

int n,c;
map<int, bool> mp;

vector<int> stall; // vi tri cac chuong

void input(){
    cin >> n >> c;
    int a;

    for(int i=0; i<n; i++){
        cin >> a;
        stall.push_back(a);
    }

    sort(stall.begin(),stall.end());
}

void process(int left, int right, int num){
    
    if(num){
        int mid = (left + right)/2;

        if(left < right){
            mp[stall[mid]] = 1;
            process(left, mid-1,(num-1)/2);
            process(mid+1, right, num-(num-1)/2);
        }
    }
}

void count(){
    int dMin = INT_MAX;
    int start;

    for(int i=0; i<n; i++){
        if(mp[stall[i]] == 1){
            start = i;
            break;
        }
    }

    int prev = start;
    for(int i=start+1; i<n; i++){
        if(mp[stall[i]] == 1){
            dMin = min(stall[i]-stall[prev], dMin);
            prev = i;
        }
    }
    cout << dMin << endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        input();
        process(0,n-1, c);
        // count();
        for(int i=0; i<n; i++){
            if(mp[stall[i]] == 1){
                cout << stall[i] <<  " ";
            }
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;


int m, n, p; // m giao vien, n mon hoc, p rang buoc

vector<int> crsList[11]; 
vector<pair<int, int>> vt;

int load[11]= {0};

int f0 = 32, f = 0; // cuc tieu ham f0

int checkCrsList[11][31] = {0};

void init(){

    cin >> m >> n;

    int a, b;
    int tmp;
    for(int i=0; i<m; i++){
        cin >> a;
        
        for(int j=0; j<a; j++){
            cin >> tmp;
            crsList[i].push_back(tmp);

        }
    }
    cin >> p;

    for(int i=0; i<p; i++){
        cin >> a >> b;
        vt.push_back({a,b});
    }

}

bool check(int i, int k){ // giao vien i (from 0), mon hoc k (from 1)
    int flag = 0;
    
    for(int j=0; j<crsList[i].size(); j++){
        if(crsList[i][j] == k){
            flag = 1;
            break;
        }
    }

    if(!flag) return false;

    for(int j=0; j<p; j++){
        if(vt[j].first == k && checkCrsList[i][vt[j].second]) return false;
        if(vt[j].second == k && checkCrsList[i][vt[j].first]) return false;   
    }

    return true;
}

void TRY(int k) { // mon hoc thu k
    for(int i=0; i<m; i++){ // chon tat ca giao vien co the day
        if(check(i, k)){
            
            load[i] += 1;
            checkCrsList[i][k] = 1;
            int tmp = f;
            f = max(f, load[i]);

            if(k==n){    
                f0 = min(f, f0);
            }
            else{
                if(f < f0){
                    TRY(k+1);
                }
                  
            }

            f = tmp;
            load[i] -= 1;
            checkCrsList[i][k] = 0;
        }
    }
}

int main(){

    init();
    TRY(1);
    cout << f0;

    return 0;
}
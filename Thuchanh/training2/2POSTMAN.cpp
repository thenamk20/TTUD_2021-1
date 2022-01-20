#include <bits/stdc++.h>

using namespace std;

int poo(int a, int b){
    return a > b;
}

int main(){

    int n, k;
    cin >> n >> k;
    int arr[1000];
    vector<int> dcAm, dcDuong;
    map<int, int> right, left; // so hang

    for(int i=1; i<=n; i++){
        int a, b;
        cin  >> a >> b;
        if(a > 0){
            dcDuong.push_back(a);
            right[a] = b;
        }
        else if( a < 0){
            dcAm.push_back(-a);
            left[-a] = b;
        }
    }

    sort(dcAm.begin(), dcAm.end(), poo);
    sort(dcDuong.begin(), dcDuong.end(), poo);
    dcDuong.push_back(0);
    dcAm.push_back(0);

    // ben > 0
    unsigned long long sum = dcDuong[0];
   
    int bring = k;
    int need = right[dcDuong[0]]; // luong hang can giao tai diem i    

    for(int i=0; i<dcDuong.size()-1; ){

        if(bring >= need){
            sum += (dcDuong[i] - dcDuong[i+1]);
            bring = bring - need;
            need = right[dcDuong[i+1]];
            i++; 
        }
        else{
            need -= bring;
            sum += 2*dcDuong[i];
            bring = k;
        }
    }

    // ben < 0
    sum += dcAm[0];

    bring = k;
    need = left[dcAm[0]]; // luong hang can giao tai diem i   

    for(int i=0; i<dcAm.size()-1; ){

        if(bring >= need){
            sum += (dcAm[i] - dcAm[i+1]);
            bring = bring - need;
            need = left[dcAm[i+1]];
            i++; 
        }
        else{
            need -= bring;
            sum += 2*dcAm[i];
            bring = k;
        }
    }

    cout << sum;

    return 0;
}
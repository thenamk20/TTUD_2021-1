#include <bits/stdc++.h>

using namespace std;

int main(){
    
    vector<int> a = {1,2,3,4,10 };
    vector<int>::iterator it;

    // tìm kiếm trên vector chưa được sắp xếp
    it = find(a.begin(), a.end(), 10);
    if(*it == 10){
        cout << "true";
    }
    else{
        cout << "false";
    }

    // tìm kiếm trên vector đã sắp xếp
    it = lower_bound(a.begin(),a.end(), 10);
    cout << *it;
    if(*it == 10){
        cout << "true";
    }
    else{
        cout << "false";
    }

    // sắp xếp trên mảng
    int c[4] = {1,5,2,7};
    sort(c, c + 4);

    for (int i=0; i<4; i++){
        cout << c[i] << endl;
    }
  
}
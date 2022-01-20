#include <bits/stdc++.h>

using namespace std;

struct Union_Find {
    vector<int> iParent;

    Union_Find(int n){
        iParent = vector<int>(n);
        for(int i=0; i<n; i++){
            iParent[i] = i;
        }
    }

    // trả về phần tử đại diện cho một tập  
    int Find(int x){
        if(iParent[x] == x){
            return x;
        }else {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }

    //hợp nhất tập chứa x và tập chứa y
    void Unite(int x, int y){
        iParent[Find(x)] = Find(y);
    }
    
};

int main(){



    return 0;
}
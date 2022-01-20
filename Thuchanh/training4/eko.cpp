#include <bits/stdc++.h>
 
#define int long long

using namespace std;
 
int n; // số cây
int m; // lượng gỗ cần lấy
int res = -1;
int hMax = INT_MIN;
 
vector<int> trees;
 
void init(){
 
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n >> m;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        trees.push_back(a);
 
        hMax = max(hMax, a);
    }

}
 
int wood (int h){
    int sum = 0;
 
    int n = trees.size();
 
    for(int i=0; i<n; i++){
        if(trees[i] > h){
            sum += (trees[i] - h);
        }
    }

    return sum;
}
 
void process(int low, int high){
 
   if(low <= high){

        int mid = (low + high) / 2;
 
        if(wood(mid) >= m){
            res = mid;
            process(mid+1, high);
        } 
        
        else{
            process(low, mid-1);
        }
        
    }
}
 
main(){
 
    init();
    process(0, hMax);
    cout << res << endl;
 
}
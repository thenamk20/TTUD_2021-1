#include <bits/stdc++.h>

using namespace std;

// chia để trị
int a[100001];

int maxToRight(int m, int r){
    int sum =  0;
    int maxR = INT_MIN;

    for(int i=m; i<=r; i++){
        sum += a[i];
        maxR = max(sum, maxR);
    }
    return maxR;
}

int maxToLeft(int m, int l){
    int sum =  0;
    int maxL = INT_MIN;

    for(int i=m; i>=l; i--){
        sum += a[i];
        maxL = max(sum, maxL);
    }
    return maxL;
}


int solve(int left, int right){
   
    if(left == right) return a[left];

    int mid = (right+left) / 2;

    int maxLeft = solve(left, mid);
    int maxRight = solve(mid+1, right);

    int maxMid = maxToRight(mid+1, right) + maxToLeft(mid, left);

    return max(max(maxLeft, maxRight), maxMid);

}

int main(){

    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << solve(0, n-1);

    return 0;
}
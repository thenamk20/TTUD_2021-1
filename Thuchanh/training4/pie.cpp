#include <bits/stdc++.h>

using namespace std;

const double PI = atan(1)*4;

const int MAX = 10005;

const double err = 1e-7;

int n,f;
double s[MAX];
double sMax;
int N = 1e9;

void input(){
    sMax = 0;
    int r;
    cin >> n >> f;
    for(int i=0; i<n; i++){
        cin >> r;
        s[i] = PI*r*r;
        sMax = max(sMax,s[i]);
    }
}

bool checkPie(double a){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += floor(s[i]/a);
    }

    return sum > f;
}

double solve(double left, double right){
    double mid = (left + right) / 2.0;
    N--;

    if(right - left < err || N < 0) return mid;
    else{
        if(checkPie(mid)) return solve(mid, right);
        else return solve(left, mid);
    }
}

int main(){

    int t;
    cin >> t;

    while(t>0) {
        input();
        printf("%.6f\n",solve(0, sMax));
        t--;
    }

    return 0;
}
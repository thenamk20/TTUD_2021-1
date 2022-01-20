#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

vector<int> timeTree; // thời gian lớn lên của mỗi cây
int n;

bool compare1(int a, int b){
    return a > b;
}

void init(){
    cin >> n;
    int day;
    for(int i=0; i<n; i++){
        cin >> day;
        timeTree.push_back(day);
    }
    sort(timeTree.begin(), timeTree.end(), compare1);
}

int solve(){
    int sum = 0;
    int maxDay = 0;
    for(int i=0; i<n; i++){
        sum++;
        maxDay--;
        maxDay = max(maxDay, timeTree[i]);
        if(maxDay == timeTree[i]) maxDay ++;
    }
    sum += maxDay;
    return sum;
}

int main(){

    init();
    cout << solve();

    return 0;
}
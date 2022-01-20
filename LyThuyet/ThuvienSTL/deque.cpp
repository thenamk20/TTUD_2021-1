#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> a = {4,5,6};
    a.push_back(1);
    a.push_front(2);
    a.pop_back();
    a.pop_front();

    for (int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }

}
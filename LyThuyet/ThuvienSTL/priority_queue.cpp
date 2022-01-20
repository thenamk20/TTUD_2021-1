#include <bits/stdc++.h>

using namespace std;

void show(priority_queue<int> a){
    priority_queue<int> b = a;
    while(!b.empty()){
        cout << b.top() << " ";
        b.pop();
    }
    cout << '\n';
}

int main(){
    priority_queue<int> a;

    a.push(1);
    a.push(10);
    a.push(4);
    a.push(2);
    a.pop(); // bỏ đi 10 (phần tử đầu tiên của priority_queue)

    show(a); // 10 4 2 1 
    
    return 0;
}
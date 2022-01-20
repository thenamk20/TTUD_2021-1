#include <bits/stdc++.h>

using namespace std;

map<char, int> button;

void init(){
    button['a'] = button['d'] = button['g'] = button['j'] = 1;
    button['w'] = button['m'] = button['p'] = button['t'] = button[' '] = 1;

    button['b'] = button['e'] = button['h'] = button['k'] = 2;
    button['n'] = button['q'] = button['u'] = button['x'] = 2;

    button['c'] = button['f'] = button['i'] = button['l'] = 3;
    button['o'] = button['r'] = button['v'] = button['y'] = 3;

    button['s'] = button['z'] = 4;

}


int solve(string s){
    int count = 0;
    for(int i=0; i<s.length(); i++){
        count += button[s[i]];
    }
    return count;
}


int main(){

    init();
    int t;  cin >> t;
    cin.ignore();

    for(int i=1; i<=t; i++){
        string s="";
        
        getline(cin, s);
        cout << "Case #" << i <<": "<< solve(s) << endl;
    }

    return 0;
}
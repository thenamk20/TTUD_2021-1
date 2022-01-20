#include <bits/stdc++.h>

using namespace std;


int main(){

    int i;
    cin >> i;
    cin.ignore();
    
    while(i--){

        string s;
        getline(cin, s);
        int n = s.length();

        if(n<=10){
            cout << s << endl;
        }
        else{
            cout << s[0] <<(n-2) <<s[n-1] <<endl;
        }

    }

    return 0;
}
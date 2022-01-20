#include <bits/stdc++.h>

using namespace std;

int charToNum(char c){
    return int(c) - 48;
}

char numToChar(int a){
    return char(a+48);
}


string sum(string a, string b){

    int n1 = a.length(), n2 = b.length();
    int i=n1-1, j=n2-1;

    string res = "";
    int mem = 0;

    while(i>=0 && j>=0){
        int m = charToNum(a[i]);
        int n = charToNum(b[j]);

        res = numToChar((m+n+mem)%10) + res;
        mem = (m+n+mem >= 10)? 1 : 0;
        
        i--;
        j--;

    }

    while(i>=0){
        int m = charToNum(a[i]);
        res = numToChar((m+mem)%10) + res;
        mem = (m+mem >= 10)? 1 : 0;
        i--;
    }

    while(j>=0){
        int n = charToNum(b[j]);
        res = numToChar((n+mem)%10) + res;
        mem = (n+mem >= 10)? 1 : 0;
        j--;
    }

    if(mem) res = "1" + res;
    return res;
}

int main(){

    string a, b;

    getline(cin, a);
    getline(cin , b);

    cout << sum(a, b);

   

    return 0;
}
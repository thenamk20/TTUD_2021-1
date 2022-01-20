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

string subtract(string a, string b){
    int n1 = a.length(), n2 = b.length();

    int i = n1-1, j = n2-1;
    int mem = 0;
    string res ="";

    while(i>=0 && j>=0){
        int m = charToNum(a[i]);
        int n = charToNum(b[j]);


        if(m>= (n+mem) ){
            res = numToChar(m-n-mem) + res;
            mem = 0;
        }
        else{
            res = numToChar(10+m-n-mem) + res;
            mem = 1;
        }

        i--;
        j--;
    }

    while(i>=0){
        int m = charToNum(a[i]);

        if(m>=mem) {
            res = numToChar(m-mem)+res;
            mem = 0;
        }
        else{
            res = numToChar(10+m-mem)+res;
            mem = 1;
        }
        i--;
    }

    return res;
}

string modtail(string a, int n){
    for(int i=0; i<n; i++){
        a+="0";
    }
    return a;
}

string modhead(string a, int n){
    for(int i=0; i<n; i++){
        a = "0" + a;
    }
    return a;
}

bool compare(string a, string b){

    int n1 = a.length(), n2 = b.length();
    bool res = true;

    if(n1 < n2){
        a = modhead(a, n2-n1);
    }
    
    else if(n2 < n1){
        b = modhead(b, n1-n2);
    }
    
    int n = a.length();

    int i = 0;
    while(i<n){
        if(charToNum(a[i]) > charToNum(b[i])){
            res = true;
            break;
        }
        else if(charToNum(a[i]) < charToNum(b[i])){
            res = false;
            break;
        }
        else{
                i++;
            }
        }

    return res;
}

string mod(string a){

    string div = "1000000007";
    int n = a.length();
    int i = n-10;

    while(i>=0){

        if(compare(a, modtail(div,i))){
            a = subtract(a,modtail(div,i)); 
        }
        else{
            i--;
        }
    }
    
    return a;
}

string process(string a){
    string res = "";
    int n = a.length();
    int m = 0;
    for(int i=0; i<n; i++){
        if(a[i]=='0'){
            m++;
        }
        else{
            break;
        }
    }
    if(m == n) return "0";
    else return a.substr(m,n-m);
}

int main(){

    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << process(mod(sum(a,b)));

    return 0;
}
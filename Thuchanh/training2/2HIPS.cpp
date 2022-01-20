#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    int a[1000];
    while(1){
        cin >> n;
        if(n==0) break;
        else {

            for(int i=0; i<n; i++) cin >> a[i];
            int res = -1;

            for(int i=0; i<n; i++){
                int min = a[i];

                if(res < min) res = min;
                int tmp = a[i];

                for(int j=i+1; j<n; j++){
                    
                    if(a[j] >= min){
                        tmp += min;
                    }
                    else{
                        if(a[j] == 0){
                            if(res < tmp) res = tmp;
                            break;
                        }
                        else{
                            tmp = (j-i+1) * a[j];
                            min = a[j];
                        }                  
                    }

                    if(res < tmp) res = tmp;
                    
                }   
            }

            cout << res << endl;
        }
    }

    return 0;
}

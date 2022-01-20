#include <iostream>
#include <cstdio>

using namespace std;

#define int long long
#define NMAX 1000006
int n,M;
int a[NMAX];

int cut_wood(int h)
{
    int sum = 0;
    for(int i=1 ; i<=n ; i++)
    if (a[i]>h)
        sum += a[i]-h;
    return sum;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n>>M;
    for(int i=1 ; i<=n ; i++)
        cin>>a[i];

    int l = 0;
    int r = __LONG_LONG_MAX__;
    int re = 0;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (cut_wood(mid) >= M)
        {
            re = mid;
            l = mid+1;
        }else r = mid-1;
    }
    cout<<re;
}

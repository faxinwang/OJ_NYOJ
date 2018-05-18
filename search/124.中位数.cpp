#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int a[maxn];

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=0;i<n; ++i) scanf("%d", &a[i]);
        sort( a, a+n);
        printf("%d\n", a[n/2]);
    }
    



    return 0;
}
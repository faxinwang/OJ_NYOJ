#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 42;
const LL INF = 1e15+5;

LL w[maxn], v[maxn];
LL N ,W;
pair<LL,LL> p[1<<(maxn/2)];

void solve()
{
    int n1 = N / 2; //枚举前半部分
    for(int i=0, n=1<<n1; i<n; ++i)
    {
        LL sw = 0, sv = 0;
        for(int j=0; j<n1; ++j)
            if(i >> j & 1)
            {
                sw += w[j];
                sv += v[j];
            }
        p[i] = make_pair(sw, sv);
    }

    sort(p, p+(1<<n1));
    int m=1; //过滤后序列末尾的后一个位置
    for(int i=1, n=1<<n1; i<n; ++i)
    {
        if(p[m-1].second < p[i].second) p[m++] = p[i];
    }

    //枚举后半部分然后在前半部分中二分搜索寻找满足重量的最大价值
    LL ans = 0;
    int n2 = N - n1;
    for(int i=1, n=1<<n2; i<n; ++i)
    {
        LL sw = 0, sv = 0;
        for(int j=0; j < n2; ++j)
        {
            if(i >> j & 1)
            {
                sw += w[n1 + j];
                sv += v[n1 + j];
            }
        }
        if(sw <= W)
        {
            LL tv = ( lower_bound(p, p+m, make_pair(W-sw, INF))-1 )->second;
            ans = max(ans, sv + tv);
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    while(~scanf("%lld%lld",&N, &W))
    {
        for(int i=0; i<N; ++i) scanf("%lld%lld",&w[i], &v[i]);
        solve();
    }
    
    

    return 0;
}

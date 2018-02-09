#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;

/*
问题描述：
求一数列中给定范围内的数的总和

解题思路：
使用前缀和。数组a[i]存储的是a[1]到a[i]的总和。
所以a[i]到a[j]的总和为 sum = a[j] - a[i-1]
*/
int a[maxn];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif

    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; ++i){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    int n,m;
    for(int i=0; i<M; ++i){
        scanf("%d%d",&n,&m);
        printf("%d\n",a[m] - a[n-1]);
    }


    return 0;
}
/*
士兵杀敌（一）
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
南将军手下有N个士兵，分别编号1到N，这些士兵的杀敌数都是已知的。

小工是南将军手下的军师，南将军现在想知道第m号到第n号士兵的总杀敌数，请你帮助小工来回答南将军吧。

注意，南将军可能会问很多次问题。

输入
只有一组测试数据
第一行是两个整数N,M，其中N表示士兵的个数(1<N<1000000)，M表示南将军询问的次数(1<M<100000)
随后的一行是N个整数，ai表示第i号士兵杀敌数目。(0<=ai<=100)
随后的M行每行有两个整数m,n，表示南将军想知道第m号到第n号士兵的总杀敌数（1<=m,n<=N)。

输出
对于每一个询问，输出总杀敌数
每个输出占一行

样例输入
5 2
1 2 3 4 5
1 3
2 4

样例输出
6
9

题目大意：
求一数列中给定范围内的数的总和

解题思路：
使用前缀和。数组a[i]存储的是a[1]到a[i]的总和。
所以a[i]到a[j]的总和为 sum = a[j] - a[i-1]
*/
#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;

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
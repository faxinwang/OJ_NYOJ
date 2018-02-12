/*
疯牛
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
农夫 John 建造了一座很长的畜栏，它包括N (2 <= N <= 100,000)个隔间，这些小隔间依次编号
为x1,...,xN (0 <= xi <= 1,000,000,000).但是，John的C (2 <= C <= N)头牛们并不喜欢这种布局，
而且几头牛放在一个隔间里，他们就要发生争斗。为了不让牛互相伤害。John决定自己给牛分配隔间，
使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是什么呢？

输入
有多组测试数据，以EOF结束。
第一行：空格分隔的两个整数N和C
第二行——第N+1行：分别指出了xi的位置

输出
每组测试数据输出一个整数，满足题意的最大的最小值，注意换行。

样例输入
5 3
1
2
8
4
9

样例输出
3

解题思路:
二分+贪心:
用二分枚举出所有可行的距离值x, 保留其中最大的一个.
值x可行是指以x为最小间隔可以安排下所有的牛. 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;

int a[maxn];
int N,C;

bool judge(int x){
	int last = a[0], cnt = 2;
	for(int i=1,n=N-1; i<n; ++i){
		if(a[i] - last >= x){
			last = a[i];
			if( a[n] - last >= x) ++cnt;
		}
	}
//	printf("x=%d cnt=%d\n",x,cnt);
	return cnt >= C;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	while(scanf("%d%d",&N,&C)!=	EOF){
		for(int i=0;i<N;++i) scanf("%d",&a[i]);
		sort(a,a+N);
		if( C <= 2 ){
			printf("%d\n", a[N-1] - a[0]);
			continue;
		}
		int L = a[0], H = a[N-1], M ,ans;
		while(L < H){
			M = L + (H-L)/2;
//			printf("%d %d %d\n",L,M,H);
			if( judge(M) ) L = M+1, ans = M;
			else H = M;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

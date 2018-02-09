/*
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

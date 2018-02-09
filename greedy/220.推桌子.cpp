/*
解题思路:
最少时间就是整个走廊中移动桌子重叠次数最多的过道的重叠次数*10.
程序中用到了差分数组,使得的算法从O(n^2)降为了O(n)
*/
#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

int a[205];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0; i<n; ++i){
			scanf("%d%d",&s,&t);
			if(s > t) swap(s,t);
			++a[(s-1)/2];
			--a[(t-1)/2+1]; 
		}
		int Max=0;
		for(int i=1; i<=200; ++i){
			a[i] += a[i-1];
			if( a[Max] < a[i]) Max = i;
		} 
		printf("%d\n",a[Max]*10);
	}
	
	
	return 0;
} 

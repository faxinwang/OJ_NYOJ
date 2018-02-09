/*
解题思路(来自http://www.cnblogs.com/maheng/p/4817346.html):
这道题属于贪心算法，首先结果最大肯定要尽量相乘，但是a[i]=1的时候相乘是没有意义的，
这时候要选择相加，那么加到左边还是右边呢？ 
(a+1)*b与a*(1+b)的问题，当a<b的时候前者的结果是要大于后者的。
但是问题又来了，2 1 1 2这组特殊的数据显然是和上句话相悖的。
*/
#include<iostream> 
#include<cstdio>
using namespace std;
int a[10005],n;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	while(scanf("%d",&n) != -1){
		for(int i=0;i<n; ++i) scanf("%d",&a[i]);
		if(a[0]==1){
			a[0]=0; ++a[1];
		}
		if(a[n-1]==1){
			++a[n-2]; --n;
		}
		for(int i=1; i<n; ++i){
			if(a[i]==1){
				a[i]=0;
				int left = i-1,right = i+1;
				while(a[left]==0) --left;
				if(a[left]==2) ++a[left];
				else if(a[left] <= a[right]) ++a[left];
				else ++a[right];
			}
		}
		long long ans = 1;
		for(int i=0;i<n; ++i){
		//	printf("%d ",a[i]);
			if(a[i]) ans = ans*a[i] % 10086;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

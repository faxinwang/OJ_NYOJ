/*
解题思路:
1.装置只能放在中心横线上,所以只有半径>=1的装置可以使用 
2.每个装置的有效覆盖长度为2*sqrt(r*r-1)
3.从半径最大的装置开始使用 
*/ 
#include<iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 610
using namespace std;
double a[maxn];
 
int main(){
#ifdef WFX
freopen("6 in.txt","r",stdin);
#endif 
	int T,n;
	scanf("%d",&T) ;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%lf",a+i); ;
		sort(a,a+n,greater<double>());
		double L = 20;
		int ans = 0;
		for(; L > 0; ++ans) L -= 2 * sqrt(a[ans]*a[ans]-1);  
		printf("%d\n",ans);
	}
	
	return 0;
}

/*
����˼·:
1.װ��ֻ�ܷ������ĺ�����,����ֻ�а뾶>=1��װ�ÿ���ʹ�� 
2.ÿ��װ�õ���Ч���ǳ���Ϊ2*sqrt(r*r-1)
3.�Ӱ뾶����װ�ÿ�ʼʹ�� 
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

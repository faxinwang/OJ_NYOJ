/*
����˼·(����http://www.cnblogs.com/maheng/p/4817346.html):
���������̰���㷨�����Ƚ�����϶�Ҫ������ˣ�����a[i]=1��ʱ�������û������ģ�
��ʱ��Ҫѡ����ӣ���ô�ӵ���߻����ұ��أ� 
(a+1)*b��a*(1+b)�����⣬��a<b��ʱ��ǰ�ߵĽ����Ҫ���ں��ߵġ�
�������������ˣ�2 1 1 2���������������Ȼ�Ǻ��Ͼ仰��㣵ġ�
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

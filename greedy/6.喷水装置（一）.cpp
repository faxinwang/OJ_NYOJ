/*
��ˮװ�ã�һ��
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3

����
����һ���ƺ����Ϊ20�ף���Ϊ2�ף�Ҫ�ں��������Ϸ��ð뾶ΪRi����ˮװ�ã�ÿ����ˮװ��
��Ч������������Ϊ���ĵİ뾶Ϊʵ��Ri(0<Ri<15)��Բ��ʪ�����г������ˮװ��i��1<i<600)����
����һ���ܰѲ�ƺȫ��ʪ����Ҫ�����ǣ�ѡ�����ٵ���ˮװ�ã���������ƺ��ȫ��ʪ��

����
��һ��m��ʾ��m���������
ÿһ��������ݵĵ�һ����һ��������n��n��ʾ����n����ˮװ�ã�����һ�У���n��ʵ��ri��
ri��ʾ����ˮװ���ܸ��ǵ�Բ�İ뾶��

���
�������װ�õĸ���
��������
2
5
2 3.2 4 4.5 6 
10
1 2 3 1 2 1.2 3 1.1 1 2

�������
2
5
*/ 

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

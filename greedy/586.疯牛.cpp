/*
��ţ
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
ũ�� John ������һ���ܳ���������������N (2 <= N <= 100,000)�����䣬��ЩС�������α��
Ϊx1,...,xN (0 <= xi <= 1,000,000,000).���ǣ�John��C (2 <= C <= N)ͷţ�ǲ���ϲ�����ֲ��֣�
���Ҽ�ͷţ����һ����������Ǿ�Ҫ����������Ϊ�˲���ţ�����˺���John�����Լ���ţ������䣬
ʹ������ͷţ֮�����С���뾡���ܵĴ���ô�����������С������ʲô�أ�

����
�ж���������ݣ���EOF������
��һ�У��ո�ָ�����������N��C
�ڶ��С�����N+1�У��ֱ�ָ����xi��λ��

���
ÿ������������һ�����������������������Сֵ��ע�⻻�С�

��������
5 3
1
2
8
4
9

�������
3

����˼·:
����+̰��:
�ö���ö�ٳ����п��еľ���ֵx, ������������һ��.
ֵx������ָ��xΪ��С������԰��������е�ţ. 
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

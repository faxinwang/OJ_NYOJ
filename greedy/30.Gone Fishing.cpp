/*
����˼·:
�����ж�ֻ��ǰ1��,2��,...n�������������ܵõ�������ջ�,�������Ž������n�����Ž��е����ֵ.
��ֻ��ǰk�������е�����������:
����ʱ���ȥ�ߵ���k��������Ҫ��ʱ��, ʣ�µ�ʱ����ǵ������õ�ʱ��.
�Ե���ʱ��Ļ��Ѳ�������̰�Ĳ���:
 ��ÿһ�������, ��ѡ��ǰǰk��������fi���ĳ���ȥ����(���ÿ��ǻ���·�ϵ�ʱ��,��Ϊ����·�ϵ�ʱ��
 �Ѿ������),���Ҽ�¼ÿ�ε�ʱ�䶼��������һ��������.
��¼�������Ž��е����ֵ����Ӧ��ʱ�仨�Ѽ�¼,��Ϊ���е�ʱ�䶼����5����Ϊ��λ���м����,���������
����ʱ��Ҫ����5.
*/
#include<iostream> 
#include<cstdio>
#include<cstring>
#define maxn 30
using namespace std;

int f[maxn],d[maxn],t[maxn];
int ans,best[maxn]; //best[]��¼���Ž���ÿ�����������ѵ�ʱ�� 

void greedy(int pos, int time){
	int plan[maxn]={0}, fish[maxn], sum=0;
	for(int i=0; i<=pos; ++i) fish[i] = f[i];
	while(time){
		int idx=0;
		for(int i=1;i<=pos;++i){
			if(fish[i] > fish[idx]) idx = i;
		}
		sum += fish[idx];
		fish[idx] -= d[idx];
		if(fish[idx]<0) fish[idx] = 0;
		++plan[idx]; //��idx�ų�������������� 
		--time; //����ʣ��ʱ�� 
	}
	if(sum > ans){ //�������Ž� 
		ans = sum;
		memset(best,0,sizeof(best));
		for(int i=0; i<=pos; ++i) best[i] = plan[i];
	}
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int n,h;
	while(scanf("%d%d",&n,&h), n){
		for(int i=0; i<n; ++i) scanf("%d", &f[i]);
		for(int i=0; i<n; ++i) scanf("%d", &d[i]);
		for(int i=1; i<n; ++i) scanf("%d", &t[i]);// 1...n-1
		h *= 12; //ת��Ϊ��5����Ϊ��λ
		int time = 0;
		for(int pos=0; pos<n && h-time > 0; ++pos){
			greedy(pos,h-time);
			time += t[pos+1];
		}
		printf("%d",best[0]*5);
		for(int i=1;i<n;++i) printf(", %d",best[i]*5);
		printf("\nNumber of fish expected: %d\n\n",ans);
		ans = 0;
	}
	
	return 0;
}

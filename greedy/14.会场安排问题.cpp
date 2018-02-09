/*
����˼·:
���������,���������л����ֹʱ��, ͬһʱ��ֻ�ܰ���һ���,Ҫ���ž����ܶ�Ļ.
̰�Ĳ���:
1.���ݻ�Ľ���ʱ������л��������.
2.��һ���һ��Ҫѡ��. 
3.�ӵڶ�����ʼ,ѡ���������,����ǰһ��ѡ��Ļʱ�䲻��ͻ�Ļ.
*/
#include<iostream> 
#include<cstdio> 
#include<algorithm>
#define maxn 10005
using namespace std;

struct Activity{
	int B,E;
	bool operator<(const Activity& act)const{ return E < act.E;	}
}act[maxn];

int arrange(int n){
	sort(act,act+n);
	int ans=1,prev=act[0].E; //��һ���һ��Ҫѡ 
	for(int i=1;i<n;++i){
		if(act[i].B > prev){ //�ж���ǰһ��ѡ��Ļ�Ƿ��ͻ 
			++ans;
			prev = act[i].E;
		}
	}
	return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d%d",&act[i].B, &act[i].E);
		printf("%d\n",arrange(n));
	}
	return 0; 
} 

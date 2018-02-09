/*
����˼·:
�Ե���ΪԲ��, �״ﷶΧdΪ�뾶��Բ, Բ��x���ཻ���õ��߶�Ϊ���Ǹõ����״�ɷ��õķ�Χ,
��¼������Щ�߶�(����),���Ҷ˵�����. ��һ���״�һ����װ�ڵ�һ��������Ҷ˵���,���β鿴
���������,�����˵�С�ڵ����״�����λ��,��������Ӧ�ĵ���Ϳ��Ա����״︲��.������
������״�����λ��, ����Ҫ��װһ���µ��״�, ���״�ҲҪ��װ�ڸ�������Ҷ˵���,����Ĵ���
����. 
*/ 
#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 1005
using namespace std;

struct Seg{
	double L, R;
	bool operator<(const Seg& p)const{ return R < p.R; } 
};

Seg seg[maxn];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,d,x,y,Case=0;
	while(scanf("%d%d",&n,&d) && (n+d)){
		bool flag = 1;
		for(int i=0;i<n;++i){
			scanf("%d%d", &x, &y);
			if(y <= d ){
				double tmp = sqrt(d*d - y*y);
				seg[i].L = x - tmp;
				seg[i].R = x + tmp; 
			}
			else flag = 0;
		}
		int ans=1;
		if(flag){
			sort(seg,seg+n);
			double cur = seg[0].R;
			for(int i=1; i<n; ++i){
				if(seg[i].L <= cur) continue;
				cur = seg[i].R;
				++ans;
			}
		}else ans = -1;
		
		printf("Case %d: %d\n",++Case, ans);
	}
	
	
	return 0;
}

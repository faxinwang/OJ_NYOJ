/*
����˼·:
�����ÿ��Բ����γ��ߵĽ��߶�,����û�л�ֻ��һ�������Բ.
����ת��Ϊ�����ٵ����串�Ƕ������������.ʹ��̰���㷨:
̰�Ĳ���: 
1. ���������䰴��˵�����.
2. ����������ѡ���Ҷ˵�ֵ���,������һ��ѡȡ���������ص�������.
3. �����һ���������˵�>0,���޽�, ����м���һ������û�б��κ����串��,���޽�. 
*/
#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<cmath>
#define maxn 10005
using namespace std;

struct Line{
	double l,r;
	bool operator<(const Line& line)const{
		return l < line.l;
	}
}line[maxn];


int main(){
#ifdef WFX
freopen("12 in.txt","r",stdin);
#endif 
	int T,n;
	double w,h,xi,ri;
	scanf("%d",&T);
	while(T--){
		cin>>n>>w>>h;
		h /= 2;
		int k=0;
		for(int i=0; i<n; ++i){
			scanf("%lf%lf",&xi,&ri);
			if( ri > h){
				double tmp = sqrt(ri*ri - h*h);
				line[k].l = xi - tmp;
				line[k].r = xi + tmp;
				++k;
			}
		}
		sort(line, line+k);
		if(n==0 || line[0].l > 0 ) printf("0\n");
		else{
			int ans=1,flag=1;
			double cur=line[0].r;
			//��ʼѡ������ 
			for(int j=1; cur < w && j<k ; ++j){
				double maxr = 0;
				for(int i=j; i<k && line[i].l < cur; ++i){
					//ѡȡ����һ��ѡȡ���������ص������Ҷ˵�ֵ�������� 
					if(line[i].r - cur > maxr) maxr = line[i].r - cur;
				}
				if(maxr == 0){ //���maxrΪ0,˵���м���һ������û�б��κ����串�� 
					flag = 0; break;
				}else{
					cur += maxr; 
					++ans;
				}
			}
			
			if(flag) printf("%d\n",ans);
			else printf("0\n");
		}
	}
	
	return 0;
}

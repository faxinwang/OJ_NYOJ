/*
����˼·:
������㷨���ž��������н������.̰�Ĳ������Ȱ��������Ҷ˵��С��������,
�Ҷ˵���ͬʱ, ����˵�Ӵ�С����(Ҳ���Ǿ����ö���������ǰ��),Ȼ��ѡ���
һ��������Ҷ˵�,���б��õ㸲�ǵ����䶼���Ժ���,��ѡ����һ��δ�����ǵ���
����Ҷ˵�.��������. 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Range{
	int L,R;
	bool operator<(const Range& r)const{
		if( R!=r.R) return R < r.R;
		return L > r.L; 
	}
}a[105];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)!= -1){
		for(int i=0; i<n; ++i) scanf("%d%d",&a[i].L, &a[i].R );
		sort(a,a+n);
		int cur = a[0].R, idx=0, ans = 0;
		while(idx < n){
			++ans;
			while(++idx < n && a[idx].L <= cur);
			cur = a[idx].R;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

/*
�ҵ�
ʱ�����ƣ�2000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�2
����
����ѧ��ʱ����ʦ����LYHһЩ�����䣬����ȡ�����ٵĵ㣬ʹ��ÿ����������������һ���㡣
�����⼸��LYH̫æ�ˣ����ǰ������

����
����������ݡ�
ÿ������������һ��N����ʾ��N�������䣨N��100)��
������N�У�ÿ������������a��b(0��a��b��100������ʾ����������˵㡣

���
���һ����������ʾ������Ҫ�Ҽ����㡣

��������
4
1 5
2 4
1 4
2 3
3
1 2
3 4
5 6
1
2 2

�������
1
3
1


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

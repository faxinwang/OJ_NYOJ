/*
Radar
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in 
the other. Each small island is a point locating in the sea side. And any radar installation, 
locating on the coasting, can only cover d distance, so an island in the sea can be covered 
by a radius installation, if the distance between them is at most d. 

We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is 
above x-axis, and the land side below. Given the position of each island in the sea, and 
given the distance of the coverage of the radar installation, your task is to write a 
program to find the minimal number of radar installations to cover all the islands. 
Note that the position of an island is represented by its x-y coordinates.

 

����
The input consists of several test cases. The first line of each case contains two 
integers n (1<=n<=1000) and d, where n is the number of islands in the sea and d 
is the distance of coverage of the radar installation. This is followed by n lines 
each containing two integers representing the coordinate of the position of each 
island. Then a blank line follows to separate the cases. 

The input is terminated by a line containing pair of zeros

���
For each test case output one line consisting of the test case number followed by 
the minimal number of radar installations needed. "-1" installation means no 
solution for that case.

��������
3 2
1 2
-3 1
2 1

1 2
0 2

0 0
�������
Case 1: 2
Case 2: 1


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

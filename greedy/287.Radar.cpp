/*
解题思路:
以岛屿为圆心, 雷达范围d为半径画圆, 圆与x轴相交所得的线段为覆盖该岛屿雷达可放置的范围,
记录所有这些线段(区间),按右端点排序. 第一个雷达一定安装在第一个区间的右端点上,依次查看
后面的区间,如果左端点小于等于雷达所在位置,则该区间对应的岛屿就可以被该雷达覆盖.如果左端
点大于雷达所在位置, 则需要安装一个新的雷达, 该雷达也要安装在该区间的右端点上,后面的处理
类似. 
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

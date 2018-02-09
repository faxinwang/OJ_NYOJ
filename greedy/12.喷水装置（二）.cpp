/*
解题思路:
计算出每个圆与矩形长边的交线段,忽略没有或只有一个交点的圆.
问题转化为用最少的区间覆盖定长区间的问题.使用贪心算法:
贪心策略: 
1. 将所有区间按左端点排序.
2. 从左到右依次选择右端点值最大,且与上一个选取的区间有重叠的区间.
3. 如果第一个区间的左端点>0,则无解, 如果中间有一段区间没有被任何区间覆盖,则无解. 
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
			//开始选择区间 
			for(int j=1; cur < w && j<k ; ++j){
				double maxr = 0;
				for(int i=j; i<k && line[i].l < cur; ++i){
					//选取与上一个选取的区间有重叠并且右端点值最大的区间 
					if(line[i].r - cur > maxr) maxr = line[i].r - cur;
				}
				if(maxr == 0){ //如果maxr为0,说明中间有一段区间没有被任何区间覆盖 
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

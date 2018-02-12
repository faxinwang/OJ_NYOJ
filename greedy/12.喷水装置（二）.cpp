/*
喷水装置（二）
时间限制：3000 ms  |  内存限制：65535 KB
难度：4

描述
有一块草坪，横向长w,纵向长为h,在它的橫向中心线上不同位置处装有n(n<=10000)个点状的喷水装置，
每个喷水装置i喷水的效果是让以它为中心半径为Ri的圆都被润湿。请在给出的喷水装置中选择尽量少
的喷水装置，把整个草坪全部润湿。

输入
第一行输入一个正整数N表示共有n次测试数据。
每一组测试数据的第一行有三个整数n,w,h，n表示共有n个喷水装置，w表示草坪的横向长度，h表示草坪的纵向长度。
随后的n行，都有两个整数xi和ri,xi表示第i个喷水装置的的横坐标（最左边为0），ri表示该喷水装置能覆盖的圆的半径。

输出
每组测试数据输出一个正整数，表示共需要多少个喷水装置，每个输出单独占一行。
如果不存在一种能够把整个草坪湿润的方案，请输出0。

样例输入
2
2 8 6
1 1
4 5
2 10 6
4 5
6 5

样例输出
1
2
*/

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

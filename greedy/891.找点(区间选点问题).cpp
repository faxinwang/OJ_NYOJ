/*
找点
时间限制：2000 ms  |  内存限制：65535 KB
难度：2
描述
上数学课时，老师给了LYH一些闭区间，让他取尽量少的点，使得每个闭区间内至少有一个点。
但是这几天LYH太忙了，你们帮帮他吗？

输入
多组测试数据。
每组数据先输入一个N，表示有N个闭区间（N≤100)。
接下来N行，每行输入两个数a，b(0≤a≤b≤100），表示区间的两个端点。

输出
输出一个整数，表示最少需要找几个点。

样例输入
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

样例输出
1
3
1


解题思路:
刘汝佳算法入门经典书上有讲这道题.贪心策略是先按照区间右端点从小到大排序,
右端点相同时, 按左端点从大到小排序(也就是尽量让短区间排在前面),然后选择第
一个区间的右端点,所有被该点覆盖的区间都可以忽略,再选择下一个未被覆盖的区
间的右端点.依此类推. 
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

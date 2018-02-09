/*
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

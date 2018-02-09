/*
解题思路:
可以把木棒看出汉诺塔上的圆盘, 那么问题就相当于所有圆盘能堆成几堆.
这里有两种解题思路:
首先对所有木棒按照W升序排序, 如果W相同, 则按L升序排序(实质就是让其中一个变量排序,
然后按另外那个变量分组).
动态规划: 
d[i]表示第i+1个木棒的组号(显然有d[0] = 1 ), d[i]的值为第0到i-1个木棒中
长度大于第i个木棒的最大的编号再加1
贪心:
每一次遍历所有的木棒, 挑选出一组木棒组成一堆汉诺塔(标记为已访问过就可以了), 看最后能组
成多少堆汉诺塔. 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5005
using namespace std;

struct Wood{
	int L,W;
	bool operator<(const Wood& wd)const{
		if(W == wd.W) return L < wd.L;
		return W < wd.W;
	}
}w[maxn];
int d[maxn];
 
int dp(int n){
	int ans=0;
	sort(w, w+n);
	d[0] = 1;
	for(int i=1; i<n; ++i){
		int k=0;
		for(int j=0; j<i; ++j)
			if(w[j].L > w[i].L && d[j] > k) k = d[j];
		d[i] = k + 1;
		if(ans < d[i]) ans = d[i];
	}
	return ans;
}

int fun(int n){
	int ans=0,flag = 1;
	sort(w,w+n);
	while(flag){
		flag = 0;
		int prev = 0;
		for(; prev<n && d[prev]; ++prev);
		if(prev < n){
			d[prev] = 1;
			++ans;
		} 
		for(int i=prev+1; i<n; ++i) if(!d[i]){
			flag = 1;	//如果有为访问过的木棒,就不能结束遍历
			if( w[prev].L <= w[i].L  ){
				d[i] = 1;
				prev = i;
			}
		}
	}
	return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0; i<n; ++i) scanf("%d%d", &w[i].L, &w[i].W);
		printf("%d\n", fun(n));
		memset(d,0,sizeof(d));
	}
	
	return 0;
}

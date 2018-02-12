/*
zkc学长的福利
时间限制：10000 ms  |  内存限制：65535 KB
难度：3
描述
又是一年ACM集训的时刻，zkc学长邀请n位同学来玩一个有奖游戏。首先，他让每个同学在左、
右手上面分别写下一个整数，zkc学长自己也在左、右手上各写一个整数。然后，让这n位同学排
成一排，zkc学长站在队伍的最前面。排好队后，所有的同学都会获得zkc学长分发的若干肉松饼，
每位同学获得的肉松饼数分别是：排在该同学前面的所有人的左手上的数的乘积除以他自己右手
上的数，然后向下取整得到的结果。 

zkc学长不希望某一个同学获得特别多的福利，所以他想请你帮他重新安排一下队伍的顺序，
使得获得福利最多的同学，所获福利尽可能的少。注意，zkc学长的位置始终在队伍的最前面。 

【数据范围】 对于100%的数据，有1 ≤ n ≤1,000，0 < a、b < 10000。

输入
第一行一个n表示n个同学
第二行两个数字代表zkc学长左手和右手的数字
接下来的n行分别代表第n个同学左手和右手的数字

输出
一个数字代表获得福利最多同学所获得福利

样例输入
3
1 1
2 3
7 4
4 6

样例输出
2


提示
按1、2、3号同学这样排列队伍，获得福利最多的同学所获得肉松饼数为2； 
按1、3、2这样排列队伍，获得福利最多的同学所获得肉松饼数为2；
按2、1、3这样排列队伍，获得福利最多的同学所获得肉松饼数为2；
按2、3、1这样排列队伍，获得福利最多的同学所获得肉松饼数为9；
按3、1、2这样排列队伍，获得福利最多的同学所获得肉松饼数为2；
按3、2、1这样排列队伍，获得福利最多的同学所获得肉松饼数为9。
因此，福利最多的同学最少获得2个肉松饼，答案输出2。


解题思路(参考 http://blog.csdn.net/a2459956664/article/details/51563617)
题目没有说是多组输入, 被坑了几次
假设对于A,B两人以前的顺序已经排好， 现在的问题就是A, B的顺序。 设前面所有人左手乘积为t; 
如果A在前，A得到的肉松饼的个数为 t/a2,  B的到的个数为(t*a1)/b2； 如果B在前, 那么A的到的
就是（t*b1)/a2, B得到的个数就是t/b2;现在的目标就让两者的最大值取最小； 现在我们发现t是对
结果没影响的。 所以显而易见就是对a1/b2  和 b1/a2 求最小。  如果我们让A排在B前面， 那么就
是a1/b2 < b1/a2, 化简就是a1*a2 < b1*b2 , 所以我们就得到了排序的比较函数。
注意结果可能超过整数范围，需要使用高精度算法。 
*/
#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

struct S{
	int a,b;
	int key;
	bool operator<(const S& s) const{ return key < s.key; }
}s[1005];

//高精度乘法 
vector<int> multi(vector<int> a, int x){
	vector<int> b;
	while(x){
		b.push_back(x % 10);
		x/=10;
	}
	reverse( a.begin(),  a.end() );
	vector<int> c(a.size() + b.size() + 5, 0);
	for(int i=0,n1=a.size(); i<n1; ++i){
		for(int j=0,n2=b.size(); j<n2; ++j){
			c[i+j] += a[i] * b[j];
		}
	}
	for(int i=0,n=c.size()-1; i<n; ++i){
		c[i+1] += c[i] / 10;
		c[i] = c[i] % 10;
	}
	while(c.size() && c.back() == 0) c.pop_back();
	reverse(c.begin(), c.end());
	return c;
}

//高精度除法(大数除小数) 
vector<int> div(vector<int> v, int x){
	int carry = 0;
	vector<int> q;
	for(int i=0,n=v.size(); i<n; ++i){
		carry = carry * 10 + v[i];
		q.push_back( carry / x );
		carry %= x;
	}
	while(q.size()>1 && q.front()==0) q.erase(q.begin());
	return q;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=-1){
		scanf("%d%d", &s[0].a, &s[0].b);
		for(int i=1;i<=n; ++i){
			scanf("%d%d",&s[i].a, &s[i].b);
			s[i].key = s[i].a * s[i].b;
		} 
		sort(s+1, s+n+1);
	
		vector<int> tmp, Max;
		tmp.push_back(1);
		Max.push_back(0);
		tmp = multi(tmp,s[0].a);
		
		for(int i=1; i<=n; ++i){
			vector<int> r = div(tmp, s[i].b);		
			if(r.size() > Max.size() || (r.size()==Max.size() && r>Max)) r.swap(Max);
			tmp = multi(tmp, s[i].a);
		}
		
		for(int i=0,n=Max.size(); i<n; ++i){
			printf("%d",Max[i]);
		}
		printf("\n");
	}
	
	return 0;
}

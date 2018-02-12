/*
独木舟上的旅行
时间限制：3000 ms  |  内存限制：65535 KB
难度：2

描述
进行一次独木舟的旅行活动，独木舟可以在港口租到，并且之间没有区别。一条独木舟最多只能
乘坐两个人，且乘客的总重量不能超过独木舟的最大承载量。我们要尽量减少这次活动中的花销，
所以要找出可以安置所有旅客的最少的独木舟条数。现在请写一个程序，读入独木舟的最大承载量、
旅客数目和每位旅客的重量。根据给出的规则，计算要安置所有旅客必须的最少的独木舟条数，并输出结果。

输入
第一行输入s,表示测试数据的组数；
每组数据的第一行包括两个整数w，n，80<=w<=200,1<=n<=300，w为一条独木舟的最大承载量,n为人数；
接下来的一组数据为每个人的重量（不能大于船的承载量）；

输出
每组人数所需要的最少独木舟的条数。

样例输入
3
85 6
5 84 85 80 84 83
90 3
90 45 60
100 5
50 50 90 40 60

样例输出
5
3
3
*/

/*
解题思路:
首先考虑当前最重的乘客, 在找一个可以和该最终的乘客同坐一条船的最重的乘客,如果找到了第二个,就让
这两个人一起乘船, 否则就让当前最重的乘客独自乘船, 因为他太重了, 连最轻的人都不能和他同坐一条船.
后面的乘客都这样操作.
如果最后还剩下一个乘客, 则让他也需要一条船. 
*/
#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#define maxn 305
using namespace std;

int a[maxn];
typedef list<int> List;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int T,w,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&w,&n);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		sort(a,a+n,greater<int>());
		List L;
		for(int i=0; i<n; ++i) L.push_back(a[i]);
		int ans=0;
		while(L.size() > 1){
			List::iterator p = L.begin();
			List::iterator q = p;
			bool flag = false;
			for( ++p; p != L.end(); ++p ){
				if( *p + *q <= w){
					L.erase(p); L.erase(q);
					++ans;
					flag = true;
					break;
				}
			}
			if(!flag){
				++ans;
				L.erase(q);
			}
		}
		if(L.size()) ++ans; //如果还剩下一个乘客,则还需要一条船 
		printf("%d\n", ans);
	}
	
	
	return 0;
}

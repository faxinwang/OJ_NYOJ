/*
会场安排问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：4

描述
学校的小礼堂每天都会有许多活动，有时间这些活动的计划时间会发生冲突，需要选择出一些活动进行举办。
小刘的工作就是安排学校小礼堂的活动，每个时间最多安排一个活动。现在小刘有一些活动计划的时间表，
他想尽可能的安排更多的活动，请问他该如何安排。

输入
第一行是一个整型数m(m<100)表示共有m组测试数据。
每组测试数据的第一行是一个整数n(1<n<10000)表示该测试数据共有n个活动。
随后的n行，每行有两个正整数Bi,Ei(0<=Bi,Ei<10000),分别表示第i个活动的起始与结束时间（Bi<=Ei)

输出
对于每一组输入，输出最多能够安排的活动数量。
每组的输出占一行

样例输入
2
2
1 10
10 11
3
1 10
10 11
11 20

样例输出
1
2

提示
注意：如果上一个活动在t时间结束，下一个活动最早应该在t+1时间开始
*/
/*
解题思路:
活动安排问题,给定了所有活动的起止时间, 同一时刻只能安排一个活动,要求安排尽可能多的活动.
贪心策略:
1.根据活动的结束时间对所有活动升序排序.
2.第一个活动一定要选择. 
3.从第二个开始,选择结束最早,且与前一个选择的活动时间不冲突的活动.
*/
#include<iostream> 
#include<cstdio> 
#include<algorithm>
#define maxn 10005
using namespace std;

struct Activity{
	int B,E;
	bool operator<(const Activity& act)const{ return E < act.E;	}
}act[maxn];

int arrange(int n){
	sort(act,act+n);
	int ans=1,prev=act[0].E; //第一个活动一定要选 
	for(int i=1;i<n;++i){
		if(act[i].B > prev){ //判断与前一个选择的活动是否冲突 
			++ans;
			prev = act[i].E;
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
		for(int i=0;i<n;++i) scanf("%d%d",&act[i].B, &act[i].E);
		printf("%d\n",arrange(n));
	}
	return 0; 
} 

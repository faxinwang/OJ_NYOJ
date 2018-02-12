/*
Yougth的最大化
时间限制：1000 ms  |  内存限制：65535 KB
难度：4
描述
Yougth现在有n个物品的重量和价值分别是Wi和Vi，你能帮他从中选出k个物品使得单位重量的价值最大吗？

输入
有多组测试数据
每组测试数据第一行有两个数n和k，接下来一行有n个数Wi和Vi。
(1<=k=n<=10000) (1<=Wi,Vi<=1000000)

输出
输出使得单位价值的最大值。（保留两位小数）

样例输入
3 2
2 2
5 3
2 1

样例输出
0.75

http://blog.csdn.net/zsc2014030403015/article/details/45037123
解题思路： 
网上说的01分数规划，不是很懂，说一下我对这道题的理解。
1.N个数中k个数的平局数不超过给定的N个数中的最大数，所以0<ans<=Max{a[1,2...N-1]} 
2.用二分法逼近最大值Low=0,High=maxai：
	ans = (Low + High) / 2
	检测ans是否可以取跟大的值，如果可以,Low = ans
	如果不可以，High = ans
3.检测方法为，取最大的k个v[i] - ans*w[i]的和，如果和大于0,说明ans可以取更大的值。
*/ 
#include<iostream> 
#include<cstdio>
#include<algorithm> 
#define maxn 10005
using namespace std;

int w[maxn],v[maxn];
double x[maxn],eps=1e-3;
int n,k;

bool check(double M){
	for(int i=0; i<n; ++i) x[i] = v[i] - M * w[i];
	sort(x,x+n,greater<double>());
	double s = 0;
	for(int i=0; i<k; ++i) s += x[i];
	return s >=0 ; 
}

double binSearch(double low, double high){
	double L = low, H = high, ans;
	while( H - L > eps ){
		double M = (H + L) / 2;
		if( check(M) ) L = M, ans=M;
		else H = M;
	}
	return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int maxv=0;
	double x,y;
	while(scanf("%d%d",&n,&k)!= -1){
		for(int i=0; i<n; ++i) scanf("%d%d",&w[i], &v[i]), maxv = max(maxv,v[i]);
		printf("%.2lf\n",binSearch(0,maxv));
	} 
	
	return 0;
}

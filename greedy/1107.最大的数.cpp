/*
最大的数
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
小明和小红在打赌说自己数学学的好，于是小花就给他们出题了，考考他们谁NB，题目是这样的给你N个数
在这n个数之间添加N-1个*或+，使结果最大，但不可以打乱原顺序，请得出这个结果
如
1 3 5
结果是（1+3）*5=20；最大
可以添加若干个括号，但一定要保证配对，但是每两个数之间只可能有一个*或+
数列最前和最后不应有+或乘
小明想赢小红但是他比较笨，请你帮帮他

输入
多组测试数据以EOF结束，每组有一个n（n<10000），然后有n个正整数a[i]（1<=a[i]<=20）

输出
输出最大的结果由于结果比较大，结果对10086取余

样例输入
3
1 2 3
3
5 1 2

样例输出
9
15


解题思路(来自http://www.cnblogs.com/maheng/p/4817346.html):
这道题属于贪心算法，首先结果最大肯定要尽量相乘，但是a[i]=1的时候相乘是没有意义的，
这时候要选择相加，那么加到左边还是右边呢？ 
(a+1)*b与a*(1+b)的问题，当a<b的时候前者的结果是要大于后者的。
但是问题又来了，2 1 1 2这组特殊的数据显然是和上句话相悖的。
*/
#include<iostream> 
#include<cstdio>
using namespace std;
int a[10005],n;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	while(scanf("%d",&n) != -1){
		for(int i=0;i<n; ++i) scanf("%d",&a[i]);
		if(a[0]==1){
			a[0]=0; ++a[1];
		}
		if(a[n-1]==1){
			++a[n-2]; --n;
		}
		for(int i=1; i<n; ++i){
			if(a[i]==1){
				a[i]=0;
				int left = i-1,right = i+1;
				while(a[left]==0) --left;
				if(a[left]==2) ++a[left];
				else if(a[left] <= a[right]) ++a[left];
				else ++a[right];
			}
		}
		long long ans = 1;
		for(int i=0;i<n; ++i){
		//	printf("%d ",a[i]);
			if(a[i]) ans = ans*a[i] % 10086;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

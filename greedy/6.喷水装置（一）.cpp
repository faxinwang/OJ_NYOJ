/*
喷水装置（一）
时间限制：3000 ms  |  内存限制：65535 KB
难度：3

描述
现有一块草坪，长为20米，宽为2米，要在横中心线上放置半径为Ri的喷水装置，每个喷水装置
的效果都会让以它为中心的半径为实数Ri(0<Ri<15)的圆被湿润，这有充足的喷水装置i（1<i<600)个，
并且一定能把草坪全部湿润，你要做的是：选择尽量少的喷水装置，把整个草坪的全部湿润。

输入
第一行m表示有m组测试数据
每一组测试数据的第一行有一个整数数n，n表示共有n个喷水装置，随后的一行，有n个实数ri，
ri表示该喷水装置能覆盖的圆的半径。

输出
输出所用装置的个数
样例输入
2
5
2 3.2 4 4.5 6 
10
1 2 3 1 2 1.2 3 1.1 1 2

样例输出
2
5
*/ 

/*
解题思路:
1.装置只能放在中心横线上,所以只有半径>=1的装置可以使用 
2.每个装置的有效覆盖长度为2*sqrt(r*r-1)
3.从半径最大的装置开始使用 
*/ 
#include<iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 610
using namespace std;
double a[maxn];
 
int main(){
#ifdef WFX
freopen("6 in.txt","r",stdin);
#endif 
	int T,n;
	scanf("%d",&T) ;
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%lf",a+i); ;
		sort(a,a+n,greater<double>());
		double L = 20;
		int ans = 0;
		for(; L > 0; ++ans) L -= 2 * sqrt(a[ans]*a[ans]-1);  
		printf("%d\n",ans);
	}
	
	return 0;
}

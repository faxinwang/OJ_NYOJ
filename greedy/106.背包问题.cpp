/*
背包问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：3

描述
现在有很多物品（它们是可以分割的），我们知道它们每个物品的单位重量的价值v和重量w（1<=v,w<=10）；
如果给你一个背包它能容纳的重量为m（10<=m<=20）,你所要做的就是把物品装到背包里，使背包里的物
品的价值总和最大。

输入
第一行输入一个正整数n（1<=n<=5）,表示有n组测试数据；
随后有n测试数据，每组测试数据的第一行有两个正整数s，m（1<=s<=10）;s表示有s个物品。接下来
的s行每行有两个正整数v，w。

输出
输出每组测试数据中背包内的物品的价值和，每次输出占一行。

样例输入
1
3 15
5 10
2 8
3 9

样例输出
65
*/

#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;

struct Obj{
	int v,w;//单价, 现有的物品总重量 
	bool operator>(const Obj& o)const { return v>o.v;}
}obj[10];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&c);
		for(int i=0; i<n; ++i) scanf("%d%d",&obj[i].v, &obj[i].w);
		sort(obj, obj+n, greater<Obj>());
		int s = 0;
		for(int i=0; i<n; ++i){
			if(c >= obj[i].w){ //取走这种单价的所有物品 
				s += obj[i].v * obj[i].w;
				c -= obj[i].w;
			} 
			else {	//背包容量不足, 之能取一部分 
				s += obj[i].v * c;
				c = 0;
				break;
			}
		}
		printf("%d\n",s);
	}
	
	
	return 0;
}

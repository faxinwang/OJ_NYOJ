/*
阶乘之和
时间限制：3000 ms  |  内存限制：65535 KB
难度：3

描述
给你一个非负数整数n，判断n是不是一些数（这些数不允许重复使用，且为正数）的阶乘之和，
如9=1！+2!+3!，如果是，则输出Yes，否则输出No；

输入
第一行有一个整数0<m<100,表示有m组测试数据；
每组测试数据有一个正整数n<1000000;

输出
如果符合条件，输出Yes，否则输出No;

样例输入
2
9
10

样例输出
Yes
No
*/


/*
解题思路:
没有用到贪心,而是用DFS暴力解决的, 就是用DFS枚举出9一下的所有阶乘组合之和,保存在数组或者集合中, 
因为10的阶乘是3628800,所以最多只需要枚举到9的阶乘组合情况. 然后在输入的时候直接查看是否存在相应
的组合数就可以了. 
*/
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
typedef long long LL;


int f[15] ={1,1,2,6};
set<int> s;

void dfs(int k,int v){
	if(k==10){
		s.insert(v);
	}else{
		dfs(k+1, v+f[k]);
		dfs(k+1, v);
	}
}

int main(){
	int T,n,x;
	for(int i=4;i<=10;++i) f[i] = f[i-1]*i, printf("%d ",f[i]);
	dfs(1,0);
	scanf("%d",&T);
	for(int i=0; i<T; ++i){
		scanf("%d",&x);
		printf("%s\n",(s.find(x) != s.end())?"Yes":"No");
	}
	
	return 0;
}

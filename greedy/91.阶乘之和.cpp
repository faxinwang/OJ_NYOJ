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

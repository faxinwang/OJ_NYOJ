/*
����˼·:
û���õ�̰��,������DFS���������, ������DFSö�ٳ�9һ�µ����н׳����֮��,������������߼�����, 
��Ϊ10�Ľ׳���3628800,�������ֻ��Ҫö�ٵ�9�Ľ׳�������. Ȼ���������ʱ��ֱ�Ӳ鿴�Ƿ������Ӧ
��������Ϳ�����. 
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

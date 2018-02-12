/*
寻找最大数（三）
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
给出一个整数N，每次可以移动2个相邻数位上的数字，最多移动K次，得到一个新的整数。
求这个新的整数的最大值是多少。

输入
多组测试数据。
每组测试数据占一行，每行有两个数N和K (1≤N≤10^18; 0≤K≤100).

输出
每组测试数据的输出占一行，输出移动后得到的新的整数的最大值。

样例输入
1990 1
100 0
9090000078001234 6

样例输出
9190
100
9907000008001234

解题思路:
从最高位开始, 每次将i到i+k范围内最大的数字移动到当前位置
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	string n;
	int k;
	while(cin>>n>>k){
		if(k == 0){
			cout<<n<<endl;
			continue;
		}
		for(int i=0; k &&  i<n.size(); ++i){
			int Max = i;
			for(int j=i+1,m=i+k; j<=m && j<n.size(); ++j) if(n[Max] < n[j]) Max = j;
			k -= Max - i;
			char ch = n[Max];
			for(int x=Max; x > i; --x) n[x] = n[x-1];
			n[i] = ch;
		}
		cout<<n<<endl;
	}

	return 0; 
} 

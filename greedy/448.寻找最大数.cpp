/*
寻找最大数
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
请在整数 n 中删除m个数字, 使得余下的数字按原次序组成的新数最大，
比如当n=92081346718538，m=10时，则新的最大数是9888

输入
第一行输入一个正整数T，表示有T组测试数据
每组测试数据占一行，每行有两个数n,m（n可能是一个很大的整数，但其位数不超过100位，
并且保证数据首位非0，m小于整数n的位数）

输出
每组测试数据的输出占一行，输出剩余的数字按原次序组成的最大新数

样例输入
2
92081346718538 10
1008908 5

样例输出
9888
98


解题思路:
把问题从去掉m个数转换为取出n个数,使结果最大.
然后从原数中取出n个数字, 每次都取当前能取的最大的数字.
然后关键是看当前能从哪些位置取数字.
列入从m个数中取n个数字(m>n), 则第一个数能从前m-n个数中取得,然后--n.
然后第二个数能从第一个数后面的m'-n个数中取得,m'是第一个取得的数字后面的数字的长度. 
*/
#include<iostream> 
#include<string>
#include<cstdio>
using namespace std;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n;
	string s;
	scanf("%d", &T);
	while(T--){
		cin>>s>>n;
		string ans;
		n = s.size() - n; //该为从原数子中取出n个数字的问题 
		do{
			int idx=0;
			for(int i=s.size()-n; i>=0; --i) if(s[i] >= s[idx]) idx = i;
			ans += s[idx];
			s = s.substr(idx+1);
		}while(--n);
		cout<<ans<<endl;
	}
	
	return 0;
}

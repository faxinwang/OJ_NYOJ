/*
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

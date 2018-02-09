/*
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

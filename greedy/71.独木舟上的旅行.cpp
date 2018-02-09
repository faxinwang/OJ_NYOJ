/*
解题思路:
首先考虑当前最重的乘客, 在找一个可以和该最终的乘客同坐一条船的最重的乘客,如果找到了第二个,就让
这两个人一起乘船, 否则就让当前最重的乘客独自乘船, 因为他太重了, 连最轻的人都不能和他同坐一条船.
后面的乘客都这样操作.
如果最后还剩下一个乘客, 则让他也需要一条船. 
*/
#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#define maxn 305
using namespace std;

int a[maxn];
typedef list<int> List;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int T,w,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&w,&n);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		sort(a,a+n,greater<int>());
		List L;
		for(int i=0; i<n; ++i) L.push_back(a[i]);
		int ans=0;
		while(L.size() > 1){
			List::iterator p = L.begin();
			List::iterator q = p;
			bool flag = false;
			for( ++p; p != L.end(); ++p ){
				if( *p + *q <= w){
					L.erase(p); L.erase(q);
					++ans;
					flag = true;
					break;
				}
			}
			if(!flag){
				++ans;
				L.erase(q);
			}
		}
		if(L.size()) ++ans; //如果还剩下一个乘客,则还需要一条船 
		printf("%d\n", ans);
	}
	
	
	return 0;
}

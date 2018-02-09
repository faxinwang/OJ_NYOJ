/*
解题思路:
1.如果田忌最快的马比齐王最快的马快, 则用最快的马对抗齐王最快的马,++ans
2.如果田忌最慢的马比齐王最慢的马快, 则用最慢的马对抗齐王最慢的马,++ans
3.如果1.2都不满足, 说明田忌最慢的马比齐王最慢的马要慢或者速度相等
	如果慢,就用田忌这头最慢的马消耗齐王那头最快的马 --ans 
	如果相等,说明两边所有的马都是一样的速度, 一直平局下去. 
*/
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
typedef multiset<int> Set;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,x;
	while( scanf("%d",&n) != EOF){
		Set t,q;
		for(int i=0; i<n; ++i) scanf("%d",&x), t.insert(x);
		for(int i=0; i<n; ++i) scanf("%d",&x), q.insert(x);
		int ans=0; 
		for(int i=0; i<n; ++i){
			if( *t.begin() > *q.begin() ){
				++ans;
				t.erase(t.begin());
				q.erase(q.begin());
			}else if( *t.rbegin() > *q.rbegin() ){
				++ans;
				t.erase(--t.end());
				q.erase(--q.end());
			}else{
				if(*t.begin() < *q.rbegin()){
					--ans;
					t.erase(t.begin());
					q.erase(--q.end());
				}else if(*t.begin() == *q.rbegin()){
					t.erase(t.begin());
					q.erase(--q.end());
				}
			}
		}
		printf("%d\n",ans*200);
	}
	
	return 0;
}

/*
����˼·:
1.������������������������, ����������Կ�����������,++ans
2.����������������������������, ������������Կ�������������,++ans
3.���1.2��������, ˵��������������������������Ҫ�������ٶ����
	�����,���������ͷ������������������ͷ������ --ans 
	������,˵���������е�����һ�����ٶ�, һֱƽ����ȥ. 
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

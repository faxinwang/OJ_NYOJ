/*
����˼·:
���ȿ��ǵ�ǰ���صĳ˿�, ����һ�����Ժ͸����յĳ˿�ͬ��һ���������صĳ˿�,����ҵ��˵ڶ���,����
��������һ��˴�, ������õ�ǰ���صĳ˿Ͷ��Գ˴�, ��Ϊ��̫����, ��������˶����ܺ���ͬ��һ����.
����ĳ˿Ͷ���������.
������ʣ��һ���˿�, ������Ҳ��Ҫһ����. 
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
		if(L.size()) ++ans; //�����ʣ��һ���˿�,����Ҫһ���� 
		printf("%d\n", ans);
	}
	
	
	return 0;
}

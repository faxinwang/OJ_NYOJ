/*
����˼·:
�ѵ�λ��������Ʒ�ӵ����˵��յ�ķ����㵽��Ʒ�ĵ�������ȥ, Ȼ�����µĵ��۶�������Ʒ��������, 
������˵Ŀ�ʼ��k��Ϊֹ. 
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
typedef long long LL;
struct Store{
	int cost, amount;
	Store(int c,int a):cost(c),amount(a){}
	bool operator<(const Store& s)const{
		return cost < s.cost;
	}
};


int main(){
#ifdef WFX
freopen("in.txt", "r", stdin);
#endif 
	int T,xi,fi,ci,n;
	scanf("%d",&T);
	while(T--){
		int K,E,N;
		vector<Store> a;
		scanf("%d%d%d", &K, &E, &N);
		for(int i=0; i<N; ++i){
			scanf("%d%d%d",&xi,&fi,&ci);
			a.push_back(Store(E - xi + ci, fi));
		}
		LL sum = 0;
		sort(a.begin(),a.end());
		for(int i=0; i<N; ++i){
			if( K > a[i].amount ){
				sum += a[i].amount * a[i].cost;
				K -= a[i].amount;
			}else{
				sum += K * a[i].cost;
				break;
			}
		}
		printf("%lld\n",sum);
	}
	
	
	return 0;
}

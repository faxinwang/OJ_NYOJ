/*简单的可分割背包问题*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Food{
	int W,F;
	double key;
	bool operator<(const Food& f)const{
		return key < f.key;
	}
}a[1005];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int M,N;
	while(scanf("%d%d",&M,&N) && (M+N)!=-2){
		for(int i=0; i<N; ++i){
			scanf("%d%d",&a[i].W, &a[i].F);
			a[i].key = 1.0 * a[i].F / a[i].W;
		}
		sort(a,a+N);
		double ans = 0;
		for(int i=0; i<N && M;++i){
			if( M >= a[i].F ){
				ans += a[i].W;
				M -= a[i].F;
			}else{
				ans += 1.0 * M / a[i].F * a[i].W;
				M = 0;
			}
		}
		printf("%.3lf\n",ans);
	}
	
	return 0;
}

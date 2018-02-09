#include<iostream> 
#include<cstdio>
using namespace std;

int a[10];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int V;
	while(scanf("%d",&V)!=EOF){
		int Min=1e5;
		for(int i=1; i<10; ++i){
			scanf("%d",&a[i]);
			Min = min(Min,a[i]);
		}
		if(Min > V){
			printf("-1"); continue;
		}
		int bit = V / Min;
		while(bit--){
			for(int j=9; j>0; --j){
				if(V >= a[j] && (V-a[j])/Min == bit ){
					printf("%d",j);
					V -= a[j];
					break;
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}

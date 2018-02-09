#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	while(scanf("%lld",&n)!=-1){
		if(n&1) printf("%lld\n",n*n*n - 3*n*n/2 + 2*n-1);
		else 	printf("%lld\n",n*n*n - 3*n*n/2 + 2*n);
	}
	return 0;
}

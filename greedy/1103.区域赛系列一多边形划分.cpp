#include<iostream> 
#include<cstdio>
using namespace std;
typedef long long LL;
LL s[20];

LL sp(int n){
	if(n==0 || n==1) return s[n]=1;
	if(s[n]) return s[n];
	
	LL sum = 0;
	for(int i=1; i<=n; ++i){
		sum += sp(i-1) * sp(n-i);
	}
	return s[n] = sum;
} 

int main(){
	int n,x;
	scanf("%d",&n);
	for(int cas=1; cas<=n; ++cas){
		scanf("%d",&x);
		printf("Case #%d : %lld\n",cas,sp(x-2));
	}
	
	return 0;
}

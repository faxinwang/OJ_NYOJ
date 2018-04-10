/*
解题思路:
其实就是一个背包容量为sum/2的0-1背包问题, 目标就是要求出最接近sum/2的一种分配方法. 
记其中一方分得的各物品重量总和为ans, 则另一方分得sum - ans的重量, 两人的重量只差就是sum - ans - ans
即 sum - 2*ans.要使该结果最小, 则ans要尽量接近sum/2. 
*/
#include<iostream>
#include<cstdio>
using namespace std;

int a[40], half,sum=0,n, ans=0;

void dfs(int k,int w){
	if(k==n){
		if(ans < w) ans = w; //ans记录最接近half的值 
	}else{
		if(w + a[k] <= half) dfs(k+1, w+a[k]);
		dfs(k+1, w);
	}
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	while(cin>>n){
		for(int i=0; i<n; ++i){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		half = sum / 2;
		dfs(0,0);
		printf("%d\n", sum - 2*ans); 
		sum = ans = 0;
	}
	
	return 0;
}

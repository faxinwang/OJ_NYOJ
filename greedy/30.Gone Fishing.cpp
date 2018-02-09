/*
解题思路:
依次判断只在前1个,2个,...n个池塘钓鱼所能得到的最大收获,最后的最优解就是这n个最优解中的最大值.
求只在前k个池塘中钓鱼的最大收益:
用总时间减去走到第k个池塘需要的时间, 剩下的时间就是钓鱼所用的时间.
对钓鱼时间的花费采用如下贪心策略:
 对每一个五分钟, 都选择当前前k个池塘中fi最大的池塘去钓鱼(不用考虑花在路上的时间,因为花在路上的时间
 已经算过了),并且记录每次的时间都花费在那一个池塘中.
记录所有最优解中的最大值和相应的时间花费记录,因为所有的时间都是以5分钟为单位进行计算的,所以最后输
出的时候要乘以5.
*/
#include<iostream> 
#include<cstdio>
#include<cstring>
#define maxn 30
using namespace std;

int f[maxn],d[maxn],t[maxn];
int ans,best[maxn]; //best[]记录最优解在每个池塘所花费的时间 

void greedy(int pos, int time){
	int plan[maxn]={0}, fish[maxn], sum=0;
	for(int i=0; i<=pos; ++i) fish[i] = f[i];
	while(time){
		int idx=0;
		for(int i=1;i<=pos;++i){
			if(fish[i] > fish[idx]) idx = i;
		}
		sum += fish[idx];
		fish[idx] -= d[idx];
		if(fish[idx]<0) fish[idx] = 0;
		++plan[idx]; //在idx号池塘花费了五分钟 
		--time; //更新剩余时间 
	}
	if(sum > ans){ //更新最优解 
		ans = sum;
		memset(best,0,sizeof(best));
		for(int i=0; i<=pos; ++i) best[i] = plan[i];
	}
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int n,h;
	while(scanf("%d%d",&n,&h), n){
		for(int i=0; i<n; ++i) scanf("%d", &f[i]);
		for(int i=0; i<n; ++i) scanf("%d", &d[i]);
		for(int i=1; i<n; ++i) scanf("%d", &t[i]);// 1...n-1
		h *= 12; //转换为以5分钟为单位
		int time = 0;
		for(int pos=0; pos<n && h-time > 0; ++pos){
			greedy(pos,h-time);
			time += t[pos+1];
		}
		printf("%d",best[0]*5);
		for(int i=1;i<n;++i) printf(", %d",best[i]*5);
		printf("\nNumber of fish expected: %d\n\n",ans);
		ans = 0;
	}
	
	return 0;
}

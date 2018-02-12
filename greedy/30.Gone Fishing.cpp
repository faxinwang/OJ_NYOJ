/*
Gone Fishing
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
John is going on a fishing trip. He has h hours available (1 <= h <= 16), and there are n 
lakes in the area (2 <= n <= 25) all reachable along a single, one-way road. John starts 
at lake 1, but he can finish at any lake he wants. He can only travel from one lake to the
 next one, but he does not have to stop at any lake unless he wishes to. For each i = 1,...,n - 1,
 the number of 5-minute intervals it takes to travel from lake i to lake i + 1 is denoted 
 ti (0 < ti <=192). For example, t3 = 4 means that it takes 20 minutes to travel from lake 
 3 to lake 4. To help plan his fishing trip, John has gathered some information about the lakes.
  For each lake i, the number of fish expected to be caught in the initial 5 minutes, denoted 
  fi( fi >= 0 ), is known. Each 5 minutes of fishing decreases the number of fish expected to 
  be caught in the next 5-minute interval by a constant rate of di (di >= 0). If the number 
  of fish expected to be caught in an interval is less than or equal to di , there will be no 
  more fish left in the lake in the next interval. To simplify the planning, John assumes that
  no one else will be fishing at the lakes to affect the number of fish he expects to catch. 
Write a program to help John plan his fishing trip to maximize the number of fish expected to 
be caught. The number of minutes spent at each lake must be a multiple of 5. 

输入
You will be given a number of cases in the input. Each case starts with a line containing n.
 This is followed by a line containing h. Next, there is a line of n integers specifying 
 fi (1 <= i <=n), then a line of n integers di (1 <=i <=n), and finally, a line of n - 1 
 integers ti (1 <=i <=n - 1). Input is terminated by a case in which n = 0. 
 
输出
For each test case, print the number of minutes spent at each lake, separated by commas, 
for the plan achieving the maximum number of fish expected to be caught (you should print
 the entire plan on one line even if it exceeds 80 characters). This is followed by a 
 line containing the number of fish expected. 
If multiple plans exist, choose the one that spends as long as possible at lake 1, even 
if no fish are expected to be caught in some intervals. If there is still a tie, choose 
the one that spends as long as possible at lake 2, and so on. Insert a blank line between cases. 

样例输入
2 
1 
10 1 
2 5 
2 
4 
4 
10 15 20 17 
0 3 4 3 
1 2 3 
4 
4 
10 15 50 30 
0 3 4 3 
1 2 3 
0 
样例输出
45, 5 
Number of fish expected: 31 

240, 0, 0, 0 
Number of fish expected: 480 

115, 10, 50, 35 
Number of fish expected: 724 
*/

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

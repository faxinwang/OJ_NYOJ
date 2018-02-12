/*
Greedy Mouse
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
A fat mouse prepared M pounds of cat food,ready to trade with the cats guarding 
the warehouse containing hisfavorite food:peanut. The warehouse has N rooms.The 
ith room containsW[i] pounds of peanut and requires F[i] pounds of cat food. 
Fatmouse does not have to trade for all the peanut in the room,instead,he may get 
W[i]*a% pounds of peanut if he pays F[i]*a% pounds of cat food.The mouse is a 
stupid mouse,so can you tell him the maximum amount of peanut he can obtain.

输入
The input consists of multiple test cases. Each test case begins with a line 
containing two non-negative integers M and N. Then N lines follow, each contains
two non-negative integers W[i] and F[i] respectively. The test case is terminated 
by two -1. All integers are not greater than 1000.

输出
For each test case, print in a single line a real number accurate up to 3 decimal 
places, which is the maximum amount of penaut that FatMouse can obtain.

样例输入
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1

样例输出
13.333
31.500

解题思路：
简单的可分割背包问题

*/
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

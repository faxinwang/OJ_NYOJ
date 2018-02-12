/*
BUYING FEED
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
Farmer John needs to travel to town to pick up K (1 <= K <= 100)pounds of feed. Driving 
D miles with K pounds of feed in his truck costs D*K cents.

The county feed lot has N (1 <= N<= 100) stores (conveniently numbered 1..N) that sell feed. 
Each store is located on a segment of the X axis whose length is E (1 <= E <= 350). Store i 
is at location X_i (0 < X_i < E) on the number line and can sell John as much as 
F_i (1 <= F_i <= 100) pounds of feed at a cost of C_i (1 <= C_i <= 1,000,000) cents per pound.
Amazingly, a given point on  the X axis might have more than one store.

Farmer John  starts  at location 0 on this number line and can drive only in the positive 
direction, ultimately arriving at location E, with at least K pounds of feed. He can stop 
at any of the feed stores along the way and buy any amount of feed up to the the store's 
limit.  What is the minimum amount Farmer John has to pay to buy and transport the K pounds 
of feed? Farmer John
knows there is a solution. Consider a sample where Farmer John  needs two pounds of feed 
from three stores (locations: 1, 3, and 4) on a number line whose range is 0..5:     
0   1   2  3   4   5    
---------------------------------         
1       1   1                Available pounds of feed         
1       2   2               Cents per pound


It is best for John to buy one pound of feed from both the second and third stores. He must 
pay two cents to buy each pound of feed for a total cost of 4. When John travels from 3 to 4 
he is moving 1 unit of length and he has 1 pound of feed so he must pay1*1 = 1 cents.

When John travels from 4 to 5 heis moving one unit and he has 2 pounds of feed so he must 
pay 1*2 = 2 cents. The total cost is 4+1+2 = 7 cents.

输入
The first line of input contains a number c giving the number of cases that follow
There are multi test cases ending with EOF.
Each case starts with a line containing three space-separated integers: K, E, and N
Then N lines follow :every line contains three space-separated integers: Xi Fi Ci
输出
For each case,Output A single integer that is the minimum cost for FJ to buy and transport the feed
样例输入
1
2 5 3                 
3 1 2
4 1 2
1 1 1

样例输出
7
*/

/*
解题思路:
把单位总量的物品从店铺运到终点的费用算到物品的单价里面去, 然后按照新的单价对所有物品进行排序, 
从最便宜的开始买够k磅为止. 
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

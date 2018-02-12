/*
Color the fence
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
Tom has fallen in love with Mary. Now Tom wants to show his love and write a number 
on the fence opposite to 

Mary’s house. Tom thinks that the larger the numbers is, the more chance to win Mary’s heart he has.

Unfortunately, Tom could only get V liters paint. He did the math and concluded that digit i 
requires ai liters paint. 

Besides,Tom heard that Mary doesn’t like zero.That’s why Tom won’t use them in his number.

Help Tom find the maximum number he can write on the fence.

输入
There are multiple test cases.
Each case the first line contains a nonnegative integer V(0≤V≤10^6).
The second line contains nine positive integers a1,a2,……，a9(1≤ai≤10^5).

输出
Printf the maximum number Tom can write on the fence. If he has too little paint for any digit, print -1.

样例输入
5
5 4 3 2 1 2 3 4 5
2
9 11 1 12 5 8 9 10 6

样例输出
55555
33
*/
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

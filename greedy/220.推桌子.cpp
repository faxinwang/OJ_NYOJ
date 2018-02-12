/*
推桌子
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
The famous ACM (Advanced Computer Maker) Company has rented a floor of a building whose 
shape is in the following figure. 

The floor has 200 rooms each on the north side and south side along the corridor. Recently 
the Company made a plan to reform its system. The reform includes moving a lot of tables
 between rooms. Because the corridor is narrow and all the tables are big, only one table
  can pass through the corridor. Some plan is needed to make the moving efficient. The
   manager figured out the following plan: Moving a table from a room to another room can be 
   done within 10 minutes. When moving a table from room i to room j, the part of the corridor 
   between the front of room i and the front of room j is used. So, during each 10 minutes, 
   several moving between two rooms not sharing the same part of the corridor will be done 
   simultaneously. To make it clear the manager illustrated the possible cases and impossible 
   cases of simultaneous moving. 


For each room, at most one table will be either moved in or moved out. Now, the manager 
seeks out a method to minimize the time to move all the tables. Your job is to write a 
program to solve the manager's problem.

输入
The input consists of T test cases. The number of test cases ) (T is given in the first 
line of the input file. Each test case begins with a line containing an integer N , 
1 <= N <= 200, that represents the number of tables to move. 
Each of the following N lines contains two positive integers s and t, representing that 
a table is to move from room number s to room number t each room number appears at most 
once in the N lines). From the 3 + N -rd 
line, the remaining test cases are listed in the same manner as above.

输出
The output should contain the minimum time in minutes to complete the moving, one per line.

样例输入
3 
4 
10 20 
30 40 
50 60 
70 80 
2 
1 3 
2 200 
3 
10 100 
20 80 
30 50

样例输出
10
20
30
*/

/*
解题思路:
最少时间就是整个走廊中移动桌子重叠次数最多的过道的重叠次数*10.
程序中用到了差分数组,使得的算法从O(n^2)降为了O(n)
*/
#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

int a[205];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0; i<n; ++i){
			scanf("%d%d",&s,&t);
			if(s > t) swap(s,t);
			++a[(s-1)/2];
			--a[(t-1)/2+1]; 
		}
		int Max=0;
		for(int i=1; i<=200; ++i){
			a[i] += a[i-1];
			if( a[Max] < a[i]) Max = i;
		} 
		printf("%d\n",a[Max]*10);
	}
	
	
	return 0;
} 

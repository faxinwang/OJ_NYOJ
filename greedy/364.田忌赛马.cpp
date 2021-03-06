/*
田忌赛马
时间限制：3000 ms  |  内存限制：65535 KB
难度：3
描述
Here is a famous story in Chinese history.

"That was about 2300 years ago. General Tian Ji was a high official in the country Qi. 
He likes to play horse racing with the king and others."

"Both of Tian and the king have three horses in different classes, namely, regular, plus, 
and super. The rule is to have three rounds in a match; each of the horses must be used 
in one round. The winner of a single round takes two hundred silver dollars from the loser."

"Being the most powerful man in the country, the king has so nice horses that in each class 
his horse is better than Tian's. As a result, each time the king takes six hundred silver 
dollars from Tian."

"Tian Ji was not happy about that, until he met Sun Bin, one of the most famous generals 
in Chinese history. Using a little trick due to Sun, Tian Ji brought home two hundred 
silver dollars and such a grace in the next match."

"It was a rather simple trick. Using his regular class horse race against the super class 
from the king, they will certainly lose that round. But then his plus beat the king's 
regular, and his super beat the king's plus. What a simple trick. And how do you think 
of Tian Ji, the high ranked official in China?"

Were Tian Ji lives in nowadays, he will certainly laugh at himself. Even more, were he 
sitting in the ACM contest right now, he may discover that the horse racing problem 
can be simply viewed as finding the maximum matching in a bipartite graph. Draw Tian's 
horses on one side, and the king's horses on the other. Whenever one of Tian's horses 
can beat one from the king, we draw an edge between them, meaning we wish to establish 
this pair. Then, the problem of winning as many rounds as possible is just to find the 
maximum matching in this graph. If there are ties, the problem becomes more complicated, 
he needs to assign weights 0, 1, or -1 to all the possible edges, and find a maximum 
weighted perfect matching...

However, the horse racing problem is a very special case of bipartite matching. The graph
is decided by the speed of the horses --- a vertex of higher speed always beat a vertex of 
lower speed. In this case, the weighted bipartite matching algorithm is a too advanced tool 
to deal with the problem.

In this problem, you are asked to write a program to solve this special case of matching problem.

输入
The input consists of many test cases. Each case starts with a positive integer n (n <= 1000) 
on the first line, which is the number of horses on each side. The next n integers on the 
second line are the speeds of Tian’s horses. Then the next n integers on the third line are 
the speeds of the king’s horses.

输出
For each input case, output a line containing a single number, which is the maximum money 
Tian Ji will get, in silver dollars.

样例输入
3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
样例输出
200
0
0


解题思路:
1.如果田忌最快的马比齐王最快的马快, 则用最快的马对抗齐王最快的马,++ans
2.如果田忌最慢的马比齐王最慢的马快, 则用最慢的马对抗齐王最慢的马,++ans
3.如果1.2都不满足, 说明田忌最慢的马比齐王最慢的马要慢或者速度相等
	如果慢,就用田忌这头最慢的马消耗齐王那头最快的马 --ans 
	如果相等,说明两边所有的马都是一样的速度, 一直平局下去. 
*/
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
typedef multiset<int> Set;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,x;
	while( scanf("%d",&n) != EOF){
		Set t,q;
		for(int i=0; i<n; ++i) scanf("%d",&x), t.insert(x);
		for(int i=0; i<n; ++i) scanf("%d",&x), q.insert(x);
		int ans=0; 
		for(int i=0; i<n; ++i){
			if( *t.begin() > *q.begin() ){
				++ans;
				t.erase(t.begin());
				q.erase(q.begin());
			}else if( *t.rbegin() > *q.rbegin() ){
				++ans;
				t.erase(--t.end());
				q.erase(--q.end());
			}else{
				if(*t.begin() < *q.rbegin()){
					--ans;
					t.erase(t.begin());
					q.erase(--q.end());
				}else if(*t.begin() == *q.rbegin()){
					t.erase(t.begin());
					q.erase(--q.end());
				}
			}
		}
		printf("%d\n",ans*200);
	}
	
	return 0;
}

/*
吝啬的国度
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
在一个吝啬的国度里有N个城市，这N个城市间只有N-1条路把这个N个城市连接起来。现在，Tom在第S号城市，
他有张该国地图，他想知道如果自己要去参观第T号城市，必须经过的前一个城市是几号城市（假设你不走重复的路）。

输入
第一行输入一个整数M表示测试数据共有M(1<=M<=5)组
每组测试数据的第一行输入一个正整数N(1<=N<=100000)和一个正整数S(1<=S<=100000)，N表示城市的总个数，
S表示参观者所在城市的编号,随后的N-1行，每行有两个正整数a,b(1<=a,b<=N)，表示第a号城市和第b号城市之
间有一条路连通。

输出
每组测试数据输N个正整数，其中，第i个数表示从S走到i号城市，必须要经过的上一个城市的编号。（其中i=S时，请输出-1）

样例输入
1
10 1
1 9
1 8
8 10
10 3
8 6
1 2
10 4
9 5
3 7

样例输出
-1 1 10 10 9 8 3 1 1 8


解题思路：
在一个具有N个顶点，N-1条边的图中，从某一点出发到达所有其他顶点时，
求达每一个顶点的前一个顶点，可以用深搜或者广搜，这里用广搜解决。
注意要避免重复访问同一个顶点,当已经求得某一个顶点的前驱顶点时，就
不在继续访问该顶点。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 100005
using namespace std;

vector<int> g[maxn]; //
queue<int> Q;
int p[maxn];
int T,n,s;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&s);
        for(int i=1; i<=n; ++i) g[i].clear();
        for(int i=1; i<n; ++i){ //n-1 edges
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(p,0,sizeof(p));
        p[s] = -1;
        //BFS
        Q.push(s);
        while(!Q.empty()){
        	int cur = Q.front(); Q.pop();
			vector<int> &v=g[cur];
			for(int i=0,len=v.size(); i<len; ++i) if( !p[v[i]] ){ 
				Q.push(v[i]);
				p[v[i]] = cur;
			}
		}
		
		for(int i=1; i<=n; ++i) printf("%d ",p[i]);
		cout<<endl;
    }
    
    return 0;
}

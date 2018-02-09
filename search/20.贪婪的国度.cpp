/*
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

#include<iostream> 
#include<cstdio>
#include<queue>
#include<cstring>
#define N 31
using namespace std;
int L,R,C;

char a[N][N][N];
struct Point3D{
	int x,y,z;
	int step;
	Point3D(){x=y=z=step=0;}
	Point3D(int x,int y,int z,int s):x(x),y(y),z(z),step(s){}
	bool operator==(const Point3D& p)const{
		return x==p.x && y==p.y && z==p.z;
	}
}S,E;

void append(queue<Point3D>& Q, Point3D p){
	if(a[p.z][p.x][p.y] == 0){
		Q.push(p);
		a[p.z][p.x][p.y] == 1;
	}
}

int BFS(){
	a[S.z][S.x][S.y] = 1;
	queue<Point3D> Q;
	Q.push(S);
	while(!Q.empty()){
		Point3D cur = Q.front(); Q.pop();
		if( cur==E ) return cur.step;
		if(cur.x+1 < R) append(Q, Point3D(cur.x+1, cur.y, cur.z, cur.step +1));
		if(cur.y+1 < C) append(Q, Point3D(cur.x, cur.y+1, cur.z, cur.step +1));
		if(cur.z+1 < L) append(Q, Point3D(cur.x, cur.y, cur.z+1, cur.step +1));
		if(0<= cur.x-1) append(Q, Point3D(cur.x-1, cur.y, cur.z, cur.step +1));
		if(0<= cur.y-1) append(Q, Point3D(cur.x, cur.y-1, cur.z, cur.step +1));
		if(0<= cur.z-1) append(Q, Point3D(cur.x, cur.y, cur.z-1, cur.step +1));
	}
	return -1;
}

int main(){
#ifdef WFX
freopen("in.txt","r", stdin);
#endif
	
	string line;
	while(cin>>L>>R>>C && L && R && C){
		memset(a,0,sizeof(a));
		for(int z=0; z<L; ++z){
			for(int x=0; x<R; ++x){
				cin>>line;
				for(int y=0; y<C; ++y){
					if(line[y] == 'S'){S.x = x; S.y = y; S.z = z;}
					if(line[y] == 'E'){E.x = x; E.y = y; E.z = z;}
					if(line[y] == '#') a[z][x][y] = 1;
				}
			}
		}
		int ans = BFS();
		if( ans!= -1 ) printf("Escaped in %d minute(s).\n",ans);
		else printf("Trapped!\n");
	}
	
	return 0;
}

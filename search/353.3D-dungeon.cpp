/*
3D dungeon
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is 
composed of unit cubes which may or may not be filled with rock. It takes one minute 
to move one unit north, south, east, west, up or down. You cannot move diagonally and 
the maze is surrounded by solid rock on all sides. 

Is an escape possible? If yes, how long will it take? 

输入
The input consists of a number of dungeons. Each dungeon description starts with a line 
containing three integers L, R and C (all limited to 30 in size). 
L is the number of levels making up the dungeon. 
R and C are the number of rows and columns making up the plan of each level. 
Then there will follow L blocks of R lines each containing C characters. Each character 
describes one cell of the dungeon. A cell full of rock is indicated by a '#' and empty 
cells are represented by a '.'. Your starting position is indicated by 'S' and the exit 
by the letter 'E'. There's a single blank line after each level. Input is terminated by 
three zeroes for L, R and C.

输出
Each maze generates one line of output. If it is possible to reach the exit, print a 
line of the form 

Escaped in x minute(s).

where x is replaced by the shortest time it takes to escape. 
If it is not possible to escape, print the line 

Trapped!

样例输入
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

样例输出
Escaped in 11 minute(s).
Trapped!

解题思路:
BFS在三维数组中搜索。用结构体记录从起点到达每个单元的位置和最小步数，
从起点开始，在每个位置可以从上下左右前后六个方向进行扩展, 直到达到
目的地或者队列为空。
需要注意的是，用于BFS的队列要声明为全局变量，否则会超内存。
*/ 


#include<iostream> 
#include<cstdio>
#include<queue>
#include<cstring>
#define N 30
using namespace std;
int L,R,C;

char a[N][N][N];
struct Point3D{
	int x,y,z;
	int step;
	Point3D(){ step=0; }
	Point3D(int x,int y,int z,int s):x(x),y(y),z(z),step(s) {}
	bool operator==(const Point3D& p)const{
		return x==p.x && y==p.y && z==p.z;
	}
}S,E;

void append(queue<Point3D>& Q, Point3D p){
	if(a[p.z][p.x][p.y] == 0)
	{
		Q.push(p);
		a[p.z][p.x][p.y] = 1;
	}
}

queue<Point3D> Q;
int BFS(){
	a[S.z][E.x][S.y] = 1;
	while(!Q.empty()) Q.pop();
	Q.push(S);
	while(!Q.empty()){
		Point3D cur = Q.front(); Q.pop();
		int x = cur.x;
		int y = cur.y;
		int z = cur.z;
		if( cur==E ) return cur.step;
		if(x+1 < R) append(Q, Point3D(x+1, y, z, cur.step +1));
		if(y+1 < C) append(Q, Point3D(x, y+1, z, cur.step +1));
		if(z+1 < L) append(Q, Point3D(x, y, z+1, cur.step +1));
		if(0<= x-1) append(Q, Point3D(x-1, y, z, cur.step +1));
		if(0<= y-1) append(Q, Point3D(x, y-1, z, cur.step +1));
		if(0<= z-1) append(Q, Point3D(x, y, z-1, cur.step +1));
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
					if(line[y] == 'S'){ S = Point3D(x,y,z,0); }
					if(line[y] == 'E'){ E = Point3D(x,y,z,0); }
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

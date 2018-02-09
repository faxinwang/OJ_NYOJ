#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;

struct Obj{
	int v,w;//单价, 现有的物品总重量 
	bool operator>(const Obj& o)const { return v>o.v;}
}obj[10];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&c);
		for(int i=0; i<n; ++i) scanf("%d%d",&obj[i].v, &obj[i].w);
		sort(obj, obj+n, greater<Obj>());
		int s = 0;
		for(int i=0; i<n; ++i){
			if(c >= obj[i].w){ //取走这种单价的所有物品 
				s += obj[i].v * obj[i].w;
				c -= obj[i].w;
			} 
			else {	//背包容量不足, 之能取一部分 
				s += obj[i].v * c;
				c = 0;
				break;
			}
		}
		printf("%d\n",s);
	}
	
	
	return 0;
}

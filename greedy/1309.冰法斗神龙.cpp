#include<iostream> 
#include<cstdio>
#define maxn 1000005
using namespace  std;

int att[maxn], frz[maxn], wait[maxn];

void solve(){
	int HP,DMG, MYHP,k;
	scanf("%d%d%d%d",&HP,&DMG,&MYHP,&k);
	int MaxAtt = -(1<<30);
	for(int i=0; i<k; ++i){
		scanf("%d%d%d", &att[i], &frz[i], &wait[i]);
		if(MaxAtt < att[i]) MaxAtt = att[i];
	}
	//最短可存活时间(s)
	int time = MYHP/DMG + ((MYHP % DMG)>0);
	for(int i=0; i<k; ++i){
		int dis = wait[i] - frz[i] ;
		//如果有一个技能满足dis <= 0,则可以仅使用该技能将冰龙杀死 
		if(dis <=0 && att[i]){ 
			printf("YES\n"); return; 
		}
		//如果有一个技能满足dis<0, 则只要有一个技能攻击力不为0, 就可以将冰龙杀死
		/*作战方法为: 先连续施放dis小于0的技能, 让冰龙的冷冻时间足够长以至于在施加
		  攻击力不为0的技能时在冷却时间结束之前冰龙依然处于冷冻状态, 这样就可以让冰
		  龙一直处于冷冻状态.(注意冷冻时间可以累加) 
		 */ 
		if(dis < 0 && MaxAtt){
			printf("YES\n"); return;
		}
		if(dis > 0){
			//dis相当于冷冻时间为0秒时,每次攻击后需要等待的时间 
			//cnt为在死之前能对冰龙施加攻击的次数 
			int cnt = time / dis + ((time % dis) > 0);
			//最后一次使用攻击力最大的技能 
			int cut = (cnt-1) * att[i] + MaxAtt;
			if(cut >= HP){
				printf("YES\n"); return;
			}
		}
		
	}
	printf("NO\n");
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int T;
	scanf("%d",&T);
	while(T--) solve();
	
	return 0;
}

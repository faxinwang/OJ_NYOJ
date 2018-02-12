/*
冰法斗神龙
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
强大的冰魔法师zz一路过关闯将，终于独自一人杀到了神龙面前。神龙的血量值为HP，
正常状态下每秒进行一次攻击，伤害值为DAMAGE。zz精通n种瞬发冰控魔法（在同一秒内，
zz发动的冰魔法要比神龙的攻击快上一点），第i（1<=i<=n）种魔法伤害值为damage[i]，
并使神龙进入冰冻状态（神龙在冰冻状态下不会进行攻击，且如果神龙在冰冻状态下再次
受到冰魔法的攻击，则冰冻时间累加），维持freeze[i]秒，使用完后有cd[i]秒的时间不
得使用任何魔法。当zz与神龙有一方的血量值小于等于0时，即判定那一方死亡。zz想杀
神龙，但是又怕死，所以请你帮他判断一下以他现有的血量hp和他的技能，能否强杀神龙。

输入
第一行输入整数T代表T组数据，T<=30
输入数据的第一行为2个整数HP（0<HP<10^8） DAMAGE (0<DAMAGE<10^8) 分别代表神龙的血
量值和神龙每次的攻击值。第二行也是2个整数hp(0<hp<10^8),n(1<=n<=1000000) 分别代表
zz的血量以及zz会的魔法种类数。第三行到n+2行每行均为3个整数damage[i](0<=damage<=100),
freeze[i](0<=freeze[i]<=100),cd[i](1<=cd[i]<=100),(1<=i<=n)分别代表第i种魔法的伤害值，
冰控时间，冷却时间。

输出
输出只有一行YES或NO，分别代表能杀死神龙和不能杀死神龙。

样例输入
2
20 4
10 2
3 1 2
5 0 1
20 3
10 2
3 1 2
5 0 1

样例输出
NO
YES
*/ 
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

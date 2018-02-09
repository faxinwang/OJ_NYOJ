/*
解题思路:
活动安排问题,给定了所有活动的起止时间, 同一时刻只能安排一个活动,要求安排尽可能多的活动.
贪心策略:
1.根据活动的结束时间对所有活动升序排序.
2.第一个活动一定要选择. 
3.从第二个开始,选择结束最早,且与前一个选择的活动时间不冲突的活动.
*/
#include<iostream> 
#include<cstdio> 
#include<algorithm>
#define maxn 10005
using namespace std;

struct Activity{
	int B,E;
	bool operator<(const Activity& act)const{ return E < act.E;	}
}act[maxn];

int arrange(int n){
	sort(act,act+n);
	int ans=1,prev=act[0].E; //第一个活动一定要选 
	for(int i=1;i<n;++i){
		if(act[i].B > prev){ //判断与前一个选择的活动是否冲突 
			++ans;
			prev = act[i].E;
		}
	}
	return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d%d",&act[i].B, &act[i].E);
		printf("%d\n",arrange(n));
	}
	return 0; 
} 

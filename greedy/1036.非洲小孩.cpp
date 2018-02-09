/*
解题思路:
这也是一个区间选点问题,给出n个区间, 选择最少的点, 使得每个区间中都至少有一个点.
贪心原则同891题.
*/ 
#include<iostream> 
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Range{
	int beg,end;
	Range(int b,int e):beg(min(b,e)),end(max(b,e)){}
	bool operator<(const Range& r)const{
		if( end != r.end ) return end < r.end;
		return beg > r.beg;
	}
};


int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,h1,m1,h2,m2;
	while(scanf("%d",&n)!=EOF){
		vector<Range> r;
		r.reserve(105);
		for(int i=0;i<n;++i){
			scanf("%d:%d-%d:%d",&h1,&m1,&h2,&m2);
			r.push_back(Range(h1*60+m1, h2*60+m2));
		}
		sort(r.begin(), r.end());
		int cur = r[0].end, ans = 0, idx = 0;
		while(idx < n){
			++ans;
			while(++idx < n && r[idx].beg <= cur ); //注意这里是<=,意思是end==beg的时候这两个区间算重合
			cur = r[idx].end;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

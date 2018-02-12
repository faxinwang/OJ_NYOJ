/*
非洲小孩
时间限制：1000 ms  |  内存限制：65535 KB
难度：2
描述
家住非洲的小孩，都很黑。为什么呢？
第一，他们地处热带，太阳辐射严重。
第二，他们不经常洗澡。（常年缺水，怎么洗澡。）
现在，在一个非洲部落里，他们只有一个地方洗澡，并且，洗澡时间很短，瞬间有木有！！
（这也是没有的办法，缺水啊！！）每个小孩有一个时间段能够洗澡。并且，他们是可以一
起洗的（不管你是男孩是女孩）。那么，什么时间洗澡，谁应该来洗，由谁决定的呢？那必
然是他们伟大的“澡”神啊。“澡”神有一个时间表，记录着该部落的小孩，什么时候段可
以洗澡。现在，“澡”神要问你，一天内，他需要最少开启和关闭多少次洗澡的水龙头呢？
因为，开启和关闭一次水龙头是非常的费力气的，即便，这也是瞬间完成的。

输入
多组数据
第一行一个0<n<=100。
接下来n行，每行一个时间段。H1H1:M1M1-H2H2:M2M2，24小时制。
保证该时间段是在一天之内的。但是，不保证，H1H1:M1M1先于H2H2:M2M2。

输出
题目描述，“澡”神最少需要开启和关闭多少次水龙头呢？

样例输入
1
00:12-12:12
3
00:12-13:14
13:13-18:00
17:00-19:14

样例输出
1
2

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

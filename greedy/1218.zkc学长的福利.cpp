/*
解题思路(参考 http://blog.csdn.net/a2459956664/article/details/51563617)
题目没有说是多组输入, 被坑了几次
假设对于A,B两人以前的顺序已经排好， 现在的问题就是A, B的顺序。 设前面所有人左手乘积为t; 
如果A在前，A得到的肉松饼的个数为 t/a2,  B的到的个数为(t*a1)/b2； 如果B在前, 那么A的到的
就是（t*b1)/a2, B得到的个数就是t/b2;现在的目标就让两者的最大值去最小； 现在我们发现t是对
结果没影响的。 所以显而易见就是对a1/b2  和 b1/a2 求最小。  如果我们让A排在B前面， 那么就
是a1/b2 < b1/a2, 化简就是a1*a2 < b1*b2 , 所以我们就的到了排序的比较函数。
*/
#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

struct S{
	int a,b;
	int key;
	bool operator<(const S& s) const{ return key < s.key; }
}s[1005];

//高精度乘法 
vector<int> multi(vector<int> a, int x){
	vector<int> b;
	while(x){
		b.push_back(x % 10);
		x/=10;
	}
	reverse( a.begin(),  a.end() );
	vector<int> c(a.size() + b.size() + 5, 0);
	for(int i=0,n1=a.size(); i<n1; ++i){
		for(int j=0,n2=b.size(); j<n2; ++j){
			c[i+j] += a[i] * b[j];
		}
	}
	for(int i=0,n=c.size()-1; i<n; ++i){
		c[i+1] += c[i] / 10;
		c[i] = c[i] % 10;
	}
	while(c.size() && c.back() == 0) c.pop_back();
	reverse(c.begin(), c.end());
	return c;
}

//高精度除法(大数除小数) 
vector<int> div(vector<int> v, int x){
	int carry = 0;
	vector<int> q;
	for(int i=0,n=v.size(); i<n; ++i){
		carry = carry * 10 + v[i];
		q.push_back( carry / x );
		carry %= x;
	}
	while(q.size()>1 && q.front()==0) q.erase(q.begin());
	return q;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif

	int n;
	while(scanf("%d",&n)!=-1){
		scanf("%d%d", &s[0].a, &s[0].b);
		for(int i=1;i<=n; ++i){
			scanf("%d%d",&s[i].a, &s[i].b);
			s[i].key = s[i].a * s[i].b;
		} 
		sort(s+1, s+n+1);
	
		vector<int> tmp, Max;
		tmp.push_back(1);
		Max.push_back(0);
		tmp = multi(tmp,s[0].a);
		
		for(int i=1; i<=n; ++i){
			vector<int> r = div(tmp, s[i].b);		
			if(r.size() > Max.size() || (r.size()==Max.size() && r>Max)) r.swap(Max);
			tmp = multi(tmp, s[i].a);
		}
		
		for(int i=0,n=Max.size(); i<n; ++i){
			printf("%d",Max[i]);
		}
		printf("\n");
	}
	
	return 0;
}

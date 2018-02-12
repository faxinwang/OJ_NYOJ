/*
�ļ���CС��
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
CС����һЩľ�������ǵĳ��Ⱥ��������Ѿ�֪������Ҫһ������������Щľ������������
��ʱ����Ҫ�ķ�һ����λ��ʱ�䣬�����i+1��ľ���������ͳ��ȶ����ڵ��ڵ�i�������ľ
������ô������ķ�ʱ�䣬������Ҫ����һ����λ��ʱ�䡣��Ϊ����ȥԼ�ᣬCС���������
��ʱ���ڰ�ľ�������꣬���ܸ�����Ӧ����������

����
��һ����һ������T(1<T<1500)����ʾ��������һ����T�顣
ÿ��������ݵĵ�һ����һ������N��1<=N<=5000��,��ʾ��N��ľ������������һ�зֱ�����N��
ľ����L��W��0 < L ,W <= 10000������һ���ո�������ֱ��ʾľ���ĳ��Ⱥ�������

���
������Щľ�������ʱ�䡣

��������
3 
5 
4 9 5 2 2 1 3 5 1 4 
3 
2 2 1 1 2 2 
3 
1 3 2 2 3 1 

�������
2
1
3
*/
/*
����˼·:
���԰�ľ��������ŵ���ϵ�Բ��, ��ô������൱������Բ���ܶѳɼ���.
���������ֽ���˼·:
���ȶ�����ľ������W��������, ���W��ͬ, ��L��������(ʵ�ʾ���������һ����������,
Ȼ�������Ǹ���������).
��̬�滮: 
d[i]��ʾ��i+1��ľ�������(��Ȼ��d[0] = 1 ), d[i]��ֵΪ��0��i-1��ľ����
���ȴ��ڵ�i��ľ�������ı���ټ�1
̰��:
ÿһ�α������е�ľ��, ��ѡ��һ��ľ�����һ�Ѻ�ŵ��(���Ϊ�ѷ��ʹ��Ϳ�����), ���������
�ɶ��ٶѺ�ŵ��. 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5005
using namespace std;

struct Wood{
	int L,W;
	bool operator<(const Wood& wd)const{
		if(W == wd.W) return L < wd.L;
		return W < wd.W;
	}
}w[maxn];
int d[maxn];
 
int dp(int n){
	int ans=0;
	sort(w, w+n);
	d[0] = 1;
	for(int i=1; i<n; ++i){
		int k=0;
		for(int j=0; j<i; ++j)
			if(w[j].L > w[i].L && d[j] > k) k = d[j];
		d[i] = k + 1;
		if(ans < d[i]) ans = d[i];
	}
	return ans;
}

int fun(int n){
	int ans=0,flag = 1;
	sort(w,w+n);
	while(flag){
		flag = 0;
		int prev = 0;
		for(; prev<n && d[prev]; ++prev);
		if(prev < n){
			d[prev] = 1;
			++ans;
		} 
		for(int i=prev+1; i<n; ++i) if(!d[i]){
			flag = 1;	//�����Ϊ���ʹ���ľ��,�Ͳ��ܽ�������
			if( w[prev].L <= w[i].L  ){
				d[i] = 1;
				prev = i;
			}
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
		for(int i=0; i<n; ++i) scanf("%d%d", &w[i].L, &w[i].W);
		printf("%d\n", fun(n));
		memset(d,0,sizeof(d));
	}
	
	return 0;
}

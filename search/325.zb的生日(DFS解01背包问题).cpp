/*
����˼·:
��ʵ����һ����������Ϊsum/2��0-1��������, Ŀ�����Ҫ�����ӽ�sum/2��һ�ַ��䷽��. 
������һ���ֵõĸ���Ʒ�����ܺ�Ϊans, ����һ���ֵ�sum - ans������, ���˵�����ֻ�����sum - ans - ans
�� sum - 2*ans.Ҫʹ�ý����С, ��ansҪ�����ӽ�sum/2. 
*/
#include<iostream>
#include<cstdio>
using namespace std;

int a[40], half,sum=0,n, ans=0;

void dfs(int k,int w){
	if(k==n){
		if(ans < w) ans = w; //ans��¼��ӽ�half��ֵ 
	}else{
		if(w + a[k] <= half) dfs(k+1, w+a[k]);
		dfs(k+1, w);
	}
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	while(cin>>n){
		for(int i=0; i<n; ++i){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		half = sum / 2;
		dfs(0,0);
		printf("%d\n", sum - 2*ans); 
		sum = ans = 0;
	}
	
	return 0;
}

/*
������ϵ��һ����λ���
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�2
����
Give you a convex��͹���Σ�, diagonal n-3 disjoint divided into n-2 triangles(ֱ��), 
for different number of methods, such as n=5, there are 5 kinds of partition method, 
as shown in Figure

����
The first line of the input is a n (1<=n<=1000), expressed n data set.
The next n lines each behavior an integer m (3<=m<=18), namely the convex edges.

���
For each give m,, output how many classification methods.
example output: Case #a : b

��������
3
3
4
5

�������
Case #1 : 1
Case #2 : 2
Case #3 : 5

����˼·��
����������ԭ���Ǻܶ���
*/ 
#include<iostream> 
#include<cstdio>
using namespace std;
typedef long long LL;
LL s[20];

LL sp(int n){
	if(n==0 || n==1) return s[n]=1;
	if(s[n]) return s[n];
	
	LL sum = 0;
	for(int i=1; i<=n; ++i){
		sum += sp(i-1) * sp(n-i);
	}
	return s[n] = sum;
} 

int main(){
	int n,x;
	scanf("%d",&n);
	for(int cas=1; cas<=n; ++cas){
		scanf("%d",&x);
		printf("Case #%d : %lld\n",cas,sp(x-2));
	}
	
	return 0;
}

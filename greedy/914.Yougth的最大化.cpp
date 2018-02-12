/*
Yougth�����
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
Yougth������n����Ʒ�������ͼ�ֵ�ֱ���Wi��Vi�����ܰ�������ѡ��k����Ʒʹ�õ�λ�����ļ�ֵ�����

����
�ж����������
ÿ��������ݵ�һ����������n��k��������һ����n����Wi��Vi��
(1<=k=n<=10000) (1<=Wi,Vi<=1000000)

���
���ʹ�õ�λ��ֵ�����ֵ����������λС����

��������
3 2
2 2
5 3
2 1

�������
0.75

http://blog.csdn.net/zsc2014030403015/article/details/45037123
����˼·�� 
����˵��01�����滮�����Ǻܶ���˵һ���Ҷ���������⡣
1.N������k������ƽ����������������N�����е������������0<ans<=Max{a[1,2...N-1]} 
2.�ö��ַ��ƽ����ֵLow=0,High=maxai��
	ans = (Low + High) / 2
	���ans�Ƿ����ȡ�����ֵ���������,Low = ans
	��������ԣ�High = ans
3.��ⷽ��Ϊ��ȡ����k��v[i] - ans*w[i]�ĺͣ�����ʹ���0,˵��ans����ȡ�����ֵ��
*/ 
#include<iostream> 
#include<cstdio>
#include<algorithm> 
#define maxn 10005
using namespace std;

int w[maxn],v[maxn];
double x[maxn],eps=1e-3;
int n,k;

bool check(double M){
	for(int i=0; i<n; ++i) x[i] = v[i] - M * w[i];
	sort(x,x+n,greater<double>());
	double s = 0;
	for(int i=0; i<k; ++i) s += x[i];
	return s >=0 ; 
}

double binSearch(double low, double high){
	double L = low, H = high, ans;
	while( H - L > eps ){
		double M = (H + L) / 2;
		if( check(M) ) L = M, ans=M;
		else H = M;
	}
	return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int maxv=0;
	double x,y;
	while(scanf("%d%d",&n,&k)!= -1){
		for(int i=0; i<n; ++i) scanf("%d%d",&w[i], &v[i]), maxv = max(maxv,v[i]);
		printf("%.2lf\n",binSearch(0,maxv));
	} 
	
	return 0;
}

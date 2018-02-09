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

double binSearch(int n, int k, double high){
	double L = 0, H = high, ans;
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
		printf("%.2lf\n",binSearch(n,k,maxv));
	} 
	
	return 0;
}

#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;

struct Obj{
	int v,w;//����, ���е���Ʒ������ 
	bool operator>(const Obj& o)const { return v>o.v;}
}obj[10];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&c);
		for(int i=0; i<n; ++i) scanf("%d%d",&obj[i].v, &obj[i].w);
		sort(obj, obj+n, greater<Obj>());
		int s = 0;
		for(int i=0; i<n; ++i){
			if(c >= obj[i].w){ //ȡ�����ֵ��۵�������Ʒ 
				s += obj[i].v * obj[i].w;
				c -= obj[i].w;
			} 
			else {	//������������, ֮��ȡһ���� 
				s += obj[i].v * c;
				c = 0;
				break;
			}
		}
		printf("%d\n",s);
	}
	
	
	return 0;
}

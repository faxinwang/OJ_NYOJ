/*
��������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3

����
�����кܶ���Ʒ�������ǿ��Էָ�ģ�������֪������ÿ����Ʒ�ĵ�λ�����ļ�ֵv������w��1<=v,w<=10����
�������һ�������������ɵ�����Ϊm��10<=m<=20��,����Ҫ���ľ��ǰ���Ʒװ�������ʹ���������
Ʒ�ļ�ֵ�ܺ����

����
��һ������һ��������n��1<=n<=5��,��ʾ��n��������ݣ�
�����n�������ݣ�ÿ��������ݵĵ�һ��������������s��m��1<=s<=10��;s��ʾ��s����Ʒ��������
��s��ÿ��������������v��w��

���
���ÿ����������б����ڵ���Ʒ�ļ�ֵ�ͣ�ÿ�����ռһ�С�

��������
1
3 15
5 10
2 8
3 9

�������
65
*/

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

/*
Ѱ�������������
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�2
����
����һ������N��ÿ�ο����ƶ�2��������λ�ϵ����֣�����ƶ�K�Σ��õ�һ���µ�������
������µ����������ֵ�Ƕ��١�

����
����������ݡ�
ÿ���������ռһ�У�ÿ����������N��K (1��N��10^18; 0��K��100).

���
ÿ��������ݵ����ռһ�У�����ƶ���õ����µ����������ֵ��

��������
1990 1
100 0
9090000078001234 6

�������
9190
100
9907000008001234

����˼·:
�����λ��ʼ, ÿ�ν�i��i+k��Χ�����������ƶ�����ǰλ��
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	string n;
	int k;
	while(cin>>n>>k){
		if(k == 0){
			cout<<n<<endl;
			continue;
		}
		for(int i=0; k &&  i<n.size(); ++i){
			int Max = i;
			for(int j=i+1,m=i+k; j<=m && j<n.size(); ++j) if(n[Max] < n[j]) Max = j;
			k -= Max - i;
			char ch = n[Max];
			for(int x=Max; x > i; --x) n[x] = n[x-1];
			n[i] = ch;
		}
		cout<<n<<endl;
	}

	return 0; 
} 

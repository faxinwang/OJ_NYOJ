/*
����˼·:
�������ȥ��m����ת��Ϊȡ��n����,ʹ������.
Ȼ���ԭ����ȡ��n������, ÿ�ζ�ȡ��ǰ��ȡ����������.
Ȼ��ؼ��ǿ���ǰ�ܴ���Щλ��ȡ����.
�����m������ȡn������(m>n), ���һ�����ܴ�ǰm-n������ȡ��,Ȼ��--n.
Ȼ��ڶ������ܴӵ�һ���������m'-n������ȡ��,m'�ǵ�һ��ȡ�õ����ֺ�������ֵĳ���. 
*/
#include<iostream> 
#include<string>
#include<cstdio>
using namespace std;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int T,n;
	string s;
	scanf("%d", &T);
	while(T--){
		cin>>s>>n;
		string ans;
		n = s.size() - n; //��Ϊ��ԭ������ȡ��n�����ֵ����� 
		do{
			int idx=0;
			for(int i=s.size()-n; i>=0; --i) if(s[i] >= s[idx]) idx = i;
			ans += s[idx];
			s = s.substr(idx+1);
		}while(--n);
		cout<<ans<<endl;
	}
	
	return 0;
}

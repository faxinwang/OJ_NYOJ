/*
zkcѧ���ĸ���
ʱ�����ƣ�10000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
����һ��ACM��ѵ��ʱ�̣�zkcѧ������nλͬѧ����һ���н���Ϸ�����ȣ�����ÿ��ͬѧ����
��������ֱ�д��һ��������zkcѧ���Լ�Ҳ���������ϸ�дһ��������Ȼ������nλͬѧ��
��һ�ţ�zkcѧ��վ�ڶ������ǰ�档�źöӺ����е�ͬѧ������zkcѧ���ַ����������ɱ���
ÿλͬѧ��õ����ɱ����ֱ��ǣ����ڸ�ͬѧǰ��������˵������ϵ����ĳ˻��������Լ�����
�ϵ�����Ȼ������ȡ���õ��Ľ���� 

zkcѧ����ϣ��ĳһ��ͬѧ����ر��ĸ�����������������������°���һ�¶����˳��
ʹ�û�ø�������ͬѧ�������������ܵ��١�ע�⣬zkcѧ����λ��ʼ���ڶ������ǰ�档 

�����ݷ�Χ�� ����100%�����ݣ���1 �� n ��1,000��0 < a��b < 10000��

����
��һ��һ��n��ʾn��ͬѧ
�ڶ����������ִ���zkcѧ�����ֺ����ֵ�����
��������n�зֱ�����n��ͬѧ���ֺ����ֵ�����

���
һ�����ִ����ø������ͬѧ����ø���

��������
3
1 1
2 3
7 4
4 6

�������
2


��ʾ
��1��2��3��ͬѧ�������ж��飬��ø�������ͬѧ��������ɱ���Ϊ2�� 
��1��3��2�������ж��飬��ø�������ͬѧ��������ɱ���Ϊ2��
��2��1��3�������ж��飬��ø�������ͬѧ��������ɱ���Ϊ2��
��2��3��1�������ж��飬��ø�������ͬѧ��������ɱ���Ϊ9��
��3��1��2�������ж��飬��ø�������ͬѧ��������ɱ���Ϊ2��
��3��2��1�������ж��飬��ø�������ͬѧ��������ɱ���Ϊ9��
��ˣ���������ͬѧ���ٻ��2�����ɱ��������2��


����˼·(�ο� http://blog.csdn.net/a2459956664/article/details/51563617)
��Ŀû��˵�Ƕ�������, �����˼���
�������A,B������ǰ��˳���Ѿ��źã� ���ڵ��������A, B��˳�� ��ǰ�����������ֳ˻�Ϊt; 
���A��ǰ��A�õ������ɱ��ĸ���Ϊ t/a2,  B�ĵ��ĸ���Ϊ(t*a1)/b2�� ���B��ǰ, ��ôA�ĵ���
���ǣ�t*b1)/a2, B�õ��ĸ�������t/b2;���ڵ�Ŀ��������ߵ����ֵȡ��С�� �������Ƿ���t�Ƕ�
���ûӰ��ġ� �����Զ��׼����Ƕ�a1/b2  �� b1/a2 ����С��  ���������A����Bǰ�棬 ��ô��
��a1/b2 < b1/a2, �������a1*a2 < b1*b2 , �������Ǿ͵õ�������ıȽϺ�����
ע�������ܳ���������Χ����Ҫʹ�ø߾����㷨�� 
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

//�߾��ȳ˷� 
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

//�߾��ȳ���(������С��) 
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

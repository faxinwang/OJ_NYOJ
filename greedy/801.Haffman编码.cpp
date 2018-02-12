/*
Haffman����
ʱ�����ƣ�1000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
������������һ������Ϥ�ɣ�����ϤҲû��ϵ���Լ���ȥ�������������ڸ���һ���ַ���
����������Ӧ��Ȩֵ�����㹹������������Ӷ�ȷ��ÿ���ַ��Ĺ��������롣��Ȼ��������
һЩС�涨��

1.�涨��������������������Ϊ0������������Ϊ1��

2.�������ַ�Ȩֵ��ͬ����ASCII��ֵС���ַ�Ϊ���ӣ����Ϊ�Һ��ӣ�

3.�������½ڵ���������ַ����������ӵ��ַ���ͬ��

4.�����ַ�ΪASCII�����32-96֮����ַ������� ������`��֮����ַ�����

����
��������������ݣ�������100�飩
ÿ�����ݵ�һ��һ������n����ʾ�ַ�������������n�У�ÿ����һ���ַ�ch��һ������weight��
��ʾ�ַ�ch����Ӧ��Ȩֵ���м��ÿո������
�������ݱ�֤ÿ��������ݵ��ַ������ظ���

���
����ÿ��������ݣ���������˳�������Ӧ���ַ��Լ����ǵĹ������������������ʽ��������

��������
3
a 10
b 5
c 8
4
a 1
b 1
c 1
d 1

�������
a:0
b:10
c:11
a:00
b:01
c:10
d:11

����˼·:
1.�����ȼ����й�����������������뽫����Ľ�����˳������ڰ�˳�������� 
2.�ö��������������������ÿ�����Ĺ���������
3.ͨ��˳����б���Ľ��ָ�밴����˳�������Ӧ���Ĺ��������롣
 
�������Ҫע�⼸������:
1.��ĸ�����˳��Ҫ�������˳����ͬ
2.�������������ʱ��ʹ�����ȼ����п��Ժܷ���ðѹ��������������,�ѵ����ڶ����ȼ����е�ʹ��,
  ��Ҫ�Զ����������, ������Ҫ��STL������һ�����˽�.
3.��Ŀ˵����������ascii��ֵ��32��96֮����ַ�,��֪����������32��96,��������Ļ�, 32�ǿո�' ',
  �������ʱ����Ҫע��һ��.
*/
#include<iostream> 
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

struct Node{
	char ch;
	int w;
	string code;
	Node *LC,*RC;
	Node(char c,int w, Node* lc=0, Node* rc=0):ch(c),w(w),LC(lc),RC(rc){}
};

//�ö�����������������Էǳ�����ع�������н��Ĺ��������� 
void dfs(Node* node, string code){
	if(!node->LC && !node->RC) node->code = code;
	if(node->LC) dfs(node->LC, code + '0');
	if(node->RC) dfs(node->RC, code + '1');
}

class CMP{
public:
	bool operator()(const Node* a, const Node* b){
		if(a->w != b->w) return a->w > b->w;
		return a->ch > b->ch;
	}
};

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	char ch;
	int N,w;
	while(scanf("%d",&N)!=-1){
		priority_queue<Node* , deque<Node*>, CMP > Q;
		deque<Node*> arr;
		for(int i=0; i<N; ++i){
			getchar();
			scanf("%c %d",&ch,&w);
			Node *node = new Node(ch,w);
			Q.push(node);
			arr.push_back(node); //����ڵ�ָ�룬���ڰ�����˳��������������� 
		}
		while(Q.size() > 1){
			Node *a = Q.top(); Q.pop();
			Node *b = Q.top(); Q.pop();
			//�������½ڵ���������ַ����������ӵ��ַ���ͬ
			Node *c = new Node(a->ch, a->w + b->w, a, b);
			Q.push(c);
		}
		Node* root = Q.top();
		dfs(root,""); 
		for(int i=0,n=arr.size(); i<n; ++i){
			printf("%c:%s\n", arr[i]->ch, arr[i]->code.c_str());
		} 
	}
	
	return 0;
}

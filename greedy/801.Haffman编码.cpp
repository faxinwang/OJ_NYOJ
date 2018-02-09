/*
解题思路:
解决本题要注意几个问题:
1.字母输出的顺序要与输入的顺序相同
2.构造哈夫曼树的时候使用优先级队列可以很方便得把哈夫曼树构造出来,难点在于对优先级队列的使用,
  需要自定义排序规则, 所以需要对STL容器有一定的了解.
3.题目说输入数据是ascii码值在32到96之间的字符,不知道包不包括32和96,如果包括的话, 32是空格' ',
  在输入的时候需要注意一下.
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
	Node(char c,int w,Node* lc=0,Node* rc=0):ch(c),w(w),LC(lc),RC(rc){}
};
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
			arr.push_back(node);
		}
		while(Q.size() > 1){
			Node *a = Q.top(); Q.pop();
			Node *b = Q.top(); Q.pop();
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

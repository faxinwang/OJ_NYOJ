/*
Haffman编码
时间限制：1000 ms  |  内存限制：65535 KB
难度：3
描述
哈弗曼编码大家一定很熟悉吧（不熟悉也没关系，自己查去。。。）。现在给你一串字符以
及它们所对应的权值，让你构造哈弗曼树，从而确定每个字符的哈弗曼编码。当然，这里有
一些小规定：

1.规定哈弗曼树的左子树编码为0，右子树编码为1；

2.若两个字符权值相同，则ASCII码值小的字符为左孩子，大的为右孩子；

3.创建的新节点所代表的字符与它的左孩子的字符相同；

4.所有字符为ASCII码表上32-96之间的字符（即“ ”到“`”之间的字符）。

输入
输入包含多组数据（不超过100组）
每组数据第一行一个整数n，表示字符个数。接下来n行，每行有一个字符ch和一个整数weight，
表示字符ch所对应的权值，中间用空格隔开。
输入数据保证每组测试数据的字符不会重复。

输出
对于每组测试数据，按照输入顺序输出相应的字符以及它们的哈弗曼编码结果，具体格式见样例。

样例输入
3
a 10
b 5
c 8
4
a 1
b 1
c 1
d 1

样例输出
a:0
b:10
c:11
a:00
b:01
c:10
d:11

解题思路:
1.用优先级队列构造哈夫曼树，在输入将构造的结点存入顺序表，便于按顺序输出结果 
2.用二叉树的先序遍历法构造每个结点的哈夫曼编码
3.通过顺序表中保存的结点指针按输入顺序输出对应结点的哈夫曼编码。
 
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
	Node(char c,int w, Node* lc=0, Node* rc=0):ch(c),w(w),LC(lc),RC(rc){}
};

//用二叉树的先序遍历可以非常方便地构造出所有结点的哈夫曼编码 
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
			arr.push_back(node); //保存节点指针，便于按输入顺序输出哈夫曼编码 
		}
		while(Q.size() > 1){
			Node *a = Q.top(); Q.pop();
			Node *b = Q.top(); Q.pop();
			//创建的新节点所代表的字符与它的左孩子的字符相同
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

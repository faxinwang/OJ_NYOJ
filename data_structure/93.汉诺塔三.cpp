#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

/*
题目描述：给定汉诺塔问题中第1根柱子上的盘子数，问在一些列移动盘子的操作中是否有非法操作
非法操作有：
    1.当从某一个柱子上移动盘子到其他柱子上去时，该柱子上没有盘子
    2.大盘子放在了小盘子上面。

解题思路：
用三个栈保存三根柱子上的盘子，没个盘子用一个正整数表示，数字越大表示盘子越大。
初始时第一个柱子上具有给定数量的盘子。然后按照指令顺序模拟整个过程，即可知道
是否有非法操作。
*/
bool check(int P,int Q){
    int a,b;
    bool legal = true;
    stack<int> s[4];
    for(int i=P;i>0; --i) s[1].push(i);
    for(int i=0;i<Q; ++i){ 
        scanf("%d%d",&a,&b);
        if(legal){
            if(s[a].empty()) { legal = false; continue; }
            if(!s[b].empty() && s[a].top() > s[b].top()) { legal = false; continue; }
            s[b].push(s[a].top());
	        s[a].pop();
        }
    }
    return legal;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
    int T,P,Q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&P,&Q);
        printf("%s\n",check(P,Q)? "legal":"illegal");
    }

    return 0;
}

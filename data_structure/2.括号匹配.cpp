/*
括号配对问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：3
描述
现在，有一行括号序列，请你检查这行括号是否配对。

输入
第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度
小于10000，且S不是空串），测试数据组数少于5组。数据保证S中只含有"[", "]", "(", ")" 四种字符

输出
每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No

样例输入
3
[(])
(])
([[]()])

样例输出
No
No
Yes

解题思路：

括号匹配，只有()[]四种字符:
准备一个栈存放字符，从左到右扫描字符串：
如果遇到左括号，将字符入栈
如果遇到右括号，查看栈顶字符是否是相匹配的左括号(如果此时栈为空，则不匹配):
    如果是，弹出栈顶字符，继续处理后续字符
    否则不匹配
最后如果栈为空则括号匹配，否则不匹配
*/

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;


char s[10005];
char p[100];

bool check(char* s){
    stack<char> stk;
    for(int i=0; s[i]; ++i){
        if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
        else{
            if(stk.empty()) return false;
            if(p[stk.top()] == p[s[i]]) stk.pop();
            else return false;
        }
    }
    return stk.empty();
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    p['('] = p[')'] = 1;
    p['['] = p[']'] = 2;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        printf("%s\n", check(s)? "Yes":"No");
    }

    return 0;
}
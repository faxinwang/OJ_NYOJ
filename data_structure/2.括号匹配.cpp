#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;


char s[10005];
char p[100];
/*
括号匹配，只有()[]四种字符:
准备一个栈存放字符，从左到右扫描字符串：
如果遇到左括号，将字符入栈
如果遇到右括号，查看栈顶字符是否是相匹配的左括号(如果此时栈为空，则不匹配):
    如果是，弹出栈顶字符，继续处理后续字符
    否则不匹配
最后如果栈为空则括号匹配，否则不匹配
*/

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
/*
表达式求值
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
ACM队的mdd想做一个计算器，但是，他要做的不仅仅是一计算一个A+B的计算器，他想实现随便输入一个表达式都能求出它的值的计算器，
现在请你帮助他来实现这个计算器吧。比如输入：“1+2/4=”，程序就输出1.50（结果保留两位小数）

输入
第一行输入一个整数n，共有n组测试数据（n<10)。
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含 + - * / 
与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数。数据保证除数不会为0

输出
每组都输出该组运算式的运算结果，输出结果保留两位小数。

样例输入
2
1.000+2/4=
((1+2)*5+1)/4=

样例输出
1.50
4.00
*/
#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

char str[1005];
int p[100];

/*表达式求值
1.准备一个符号栈和一个数据栈，从左到右扫描表达式：
2.如果遇到的是数字，将数字放入数据栈(注意数据位数大于1位的情况)
3.如果遇到的是运算符,则：
    1.如果是左括号，则直接放入符号栈
    2.如果是右括号，则将符号栈中的符号逐个弹出并从数据栈中取出两个数进行相应的运算(先取出的作为右操作数，
      后取出的为左操作数)，每次运算后将结果放入数据栈。直到遇到对应的左括号。
    3.如果是其他符号，则
        1.如果符号栈为空，则直接将该运算符放入符号栈：
        2.否则：比较栈顶运算符和当前运算符的优先级：
            1.如果当前运算符的优先级大于栈顶运算符的优先级，将当前运算符放入符号栈。
            2.否则：取出符号栈中优先级比当前运算符高或相等的符号进行相应的运算，将运算结果放入数据栈。
              重复该操作直到符号栈为空或者栈顶为左括号。然后将该运算符放入符号栈。
4.扫描完毕后，逐个取出符号栈中剩余的运算符进行相应运算，并将运算结果放入数据栈。
5.最后，符号栈应为空，数据栈应只剩下一个数，此数即为表达式的结果。
*/

double doCal(char op, double a,double b){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
//         default : printf("error: %c %lf %lf\n",op,a,b);
    }
}

double readFloat(char* s, int &i){
    double x = 0, y=0, t=1;
    while( isdigit(s[i]) ){ x = x * 10 + s[i] - '0'; ++i; }
    if(s[i] == '.'){
        ++i;
        while( isdigit(s[i]) ){ t /= 10; y += t * (s[i]-'0'); ++i; }
        x += y;
    }
    --i;
    return x;
}

double calcul(char* s){
    stack<double> dat;
    stack<char> op;
    for(int i=0; s[i] != '='; ++i){
        if(isdigit(s[i])) {
            //读取浮点数，放入数据栈
            dat.push( readFloat(s,i) );
        }
        else if(s[i] == '('){
            //左括号入栈
            op.push(s[i]);
        }
        else if(s[i] == ')'){
            //取出运算符进行运算直到遇到左括号
            do{
                char ch = op.top(); op.pop();
                if(ch == '(') break;
                double b = dat.top();  dat.pop();
                double a = dat.top();  dat.pop();
                dat.push(doCal(ch, a, b));
            }while(1);
        }
        else if(op.empty()){ 
            //符号栈为空，当前运算符直接入栈。
            op.push(s[i]);
        } 
        else{
            //如果优先级比栈顶符号高，则该运算符直接入栈
            if(p[ s[i] ] > p[ op.top() ] ) op.push(s[i]);
            //否则取出优先级较高或相等的进行运算，并将结果放入数据栈，将当前运算符放入符号栈
            else{
                while(!op.empty()){
                    if(op.top()=='(') break;
                    if(p[op.top()] >= p[s[i]]){
                        char ch = op.top();  op.pop();
                        double b = dat.top();  dat.pop();
                        double a = dat.top();  dat.pop();
                        dat.push(doCal(ch, a, b));
                    }else break;
                }
                op.push(s[i]); //当前运算符入栈
            }
        }

    }
    //取出剩余的运算符进行运算
    while(!op.empty()){
        char ch = op.top();  op.pop();
        double b = dat.top();  dat.pop();
        double a = dat.top();  dat.pop();
        dat.push(doCal(ch, a, b));
    }
    return dat.top();
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    p['+'] = p['-'] = 1;
    p['*'] = p['/'] = 2;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        printf("%.2lf\n", calcul(str));
    }

    return 0;
}

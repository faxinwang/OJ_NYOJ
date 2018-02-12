/*
Binary String Matching
时间限制：3000 ms  |  内存限制：65535 KB
难度：3
描述
Given two strings A and B, whose alphabet consist only ‘0’ and ‘1’. Your task is only to tell how 
many times does A appear as a substring of B? For example, the text string B is ‘1001110110’ while 
the pattern string A is ‘11’, you should output 3, because the pattern A appeared at the posit

输入
The first line consist only one integer N, indicates N cases follows. In each case, there are two 
lines, the first line gives the string A, length (A) <= 10, and the second line gives the string B, 
length (B) <= 1000. And it is guaranteed that B is always longer than A.

输出
For each case, output a single line consist a single integer, tells how many times do B appears 
as a substring of A.

样例输入
3
11
1001110110
101
110010010010001
1010
110100010101011 

样例输出
3
0
3 

这里采用了最朴素的字符串匹配算法。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char p[20],s[1005];

/*统计A串在B串中出现的次数：*/

//如果p与s的开头匹配，则返回true
bool match(char* p, char* s){
    for(int i=0; p[i]; ++i) if(p[i]!=s[i]) return false;
    return true;
}

//从 0 到 strlen(s) - strlen(p) 查看p与s的开头是否匹配,统计匹配的次数.
int countMatch(char* p, char*s){
    int ans =0;
    for(int i=0,n=strlen(s)-strlen(p); i<=n; ++i){ //notice i<=n 
        if(match(p, s+i)) ++ans;
    }
    return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",p,s);
        printf("%d\n",countMatch(p,s));
    }

    return 0;
}
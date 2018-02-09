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
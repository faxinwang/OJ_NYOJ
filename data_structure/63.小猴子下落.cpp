#include<iostream>
#include<cstdio>
using namespace std;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int a,d;
    while(scanf("%d%d",&d,&a) && (a+d)){
        int ans = 1;
        for(int i=1;i<d;++i){ //往下落d-1次
            if(a % 2){ //奇数往左走
                ans = ans * 2; //变为左子结点的编号
                a = a / 2 + 1;
            }
            else{
                ans = ans * 2 + 1; //变为右子结点的编号
                a /= 2;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
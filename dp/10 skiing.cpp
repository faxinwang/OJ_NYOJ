#include<iostream>
#include<cstdio>
#define N 105
using namespace std;

int a[N][N], d[N][N];

int Dist(int x,int y, int step){
    
}

int main(){
    int T, R,C;
    int Hx=0,Hy=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d", &R, &C);
        for(int i=0;i<R;++i){
            for(int j=0; j<C;++j){
                scanf("%d%d",&a[i][j]);
            }
        }
        
        printf("%d\n", Dist(Hx,Hy,0));

    }


    return 0;
}
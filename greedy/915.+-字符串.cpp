/*
解题思路:
第一个字符串中的第一个加号和第二个字符串中的第一个加号之间的距离就是第一个字符串中第一个
加号要移动(交换)的次数,第一个字符串中的第二个加号与第二个字符串中的第二个加号的距离就是
第一个字符串中的第二个加号要移动的次数,后面的依次类推. (在加号个数相同的情况下)由于第一个
字符串中的加号最终都要与第二个字符串中的加号处在相同的位置, 所以就算第二个字符串中的第一个
加号的位置比较靠后,在第一个字符串的该位置前面有多个加号, 按题目要求 ,加号只能跟减号交换位置,
不能越过其他的加号, 所以必须先移开挡在前面的加号, 但这些加号迟早都是要移走的, 所以总的移动
次数是不变的, 所以加号ai与bi的距离就是a,b字符串中第i个加号最终需要移动的步数.
所以这道题看起来难度是1, 但也未必比难度2,3的题目简单啊. 
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int abs(int x){
	return x>0?x:-x;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	string a,b;
	while(cin>>a>>b){
		int ans = 0, i=0, j=-1, ok=1, n = a.size();
		for( ; i<n; ++i){
			if(a[i]=='+'){
				while(++j < n && b[j]!='+');
				if(j == n){
					ok = 0; break;
				}
				ans += abs(i - j);
			}
		}
		while(++j < n && b[j]!='+'); //看b的后面是否还有多余的加号. 
		if(j < n) ok = 0;
		if(ok)	printf("%d\n",ans);
		else	printf("-1\n");
	}
	
	return 0;
}

/*
Dinner
ʱ�����ƣ�100 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�1

����
Little A is one member of ACM team. He had just won the gold in World Final. To celebrate,
 he decided to invite all to have one meal. As bowl, knife and other tableware is not 
 enough in the kitchen, Little A goes to take backup tableware in warehouse. There are 
 many boxes in warehouse, one box contains only one thing, and each box is marked by the 
 name of things inside it. For example, if "basketball" is written on the box, which means 
 the box contains only basketball. With these marks, Little A wants to find out the tableware 
 easily. So, the problem for you is to help him, find out all the tableware from all boxes 
 in the warehouse.
 
����
There are many test cases. Each case contains one line, and one integer N at the first, 
N indicates that there are N boxes in the warehouse. Then N strings follow, each string 
is one name written on the box.

���
For each test of the input, output all the name of tableware.

��������
3 basketball fork chopsticks
2 bowl letter

�������
fork chopsticks
bowl

��ʾ
The tableware only contains: bowl, knife, fork and chopsticks.
*/
#include<iostream>
#include<cstdio> 
#include<string>
using namespace std;

string tw[]={"bowl", "knife", "fork", "chopsticks"};

int main(){
	int N;
	string s;
	while(cin>>N){
		for(int i=0;i<N;++i){
			cin>>s;
			for(int j=0; j<4; ++j) if(s==tw[j]){
				cout<<tw[j]<<" ";
				break;
			}
		}
		cout<<endl;
	}
	
	
	return 0;
}

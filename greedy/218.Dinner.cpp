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

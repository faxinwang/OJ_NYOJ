#include<iostream> 
#include<cstdio>
#define maxn 1000005
using namespace  std;

int att[maxn], frz[maxn], wait[maxn];

void solve(){
	int HP,DMG, MYHP,k;
	scanf("%d%d%d%d",&HP,&DMG,&MYHP,&k);
	int MaxAtt = -(1<<30);
	for(int i=0; i<k; ++i){
		scanf("%d%d%d", &att[i], &frz[i], &wait[i]);
		if(MaxAtt < att[i]) MaxAtt = att[i];
	}
	//��̿ɴ��ʱ��(s)
	int time = MYHP/DMG + ((MYHP % DMG)>0);
	for(int i=0; i<k; ++i){
		int dis = wait[i] - frz[i] ;
		//�����һ����������dis <= 0,����Խ�ʹ�øü��ܽ�����ɱ�� 
		if(dis <=0 && att[i]){ 
			printf("YES\n"); return; 
		}
		//�����һ����������dis<0, ��ֻҪ��һ�����ܹ�������Ϊ0, �Ϳ��Խ�����ɱ��
		/*��ս����Ϊ: ������ʩ��disС��0�ļ���, �ñ������䶳ʱ���㹻����������ʩ��
		  ��������Ϊ0�ļ���ʱ����ȴʱ�����֮ǰ������Ȼ�����䶳״̬, �����Ϳ����ñ�
		  ��һֱ�����䶳״̬.(ע���䶳ʱ������ۼ�) 
		 */ 
		if(dis < 0 && MaxAtt){
			printf("YES\n"); return;
		}
		if(dis > 0){
			//dis�൱���䶳ʱ��Ϊ0��ʱ,ÿ�ι�������Ҫ�ȴ���ʱ�� 
			//cntΪ����֮ǰ�ܶԱ���ʩ�ӹ����Ĵ��� 
			int cnt = time / dis + ((time % dis) > 0);
			//���һ��ʹ�ù��������ļ��� 
			int cut = (cnt-1) * att[i] + MaxAtt;
			if(cut >= HP){
				printf("YES\n"); return;
			}
		}
		
	}
	printf("NO\n");
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int T;
	scanf("%d",&T);
	while(T--) solve();
	
	return 0;
}

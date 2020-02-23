#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void get_num(int k){
	
	
		int *cnt=new int[k+1];
		for(int i=0;i<=k;i++)
			cnt[i]=0;
		int index=k;
		while(index>1)
		{
			for(int i=2;i<=k;i++)
			{
				if(index%i==0)
				{
					cnt[i]++;
					index/=i;
					break;
				}
			}
		}
		
		for(int i=2;i<=k;i++)
			if(cnt[i]>=1)
				printf("%d %d\n",i,cnt[i]);
		
		delete cnt;
	
}

int main(int argc, char** argv) {


	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int k;
		cin>>k;
		get_num(k);
	}
	return 0;
}

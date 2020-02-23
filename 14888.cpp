#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1001;
int a[MAX]={0,};
int n;
int pl,mi,mu,di;

int maxans=-1000000001;
int minans=1000000001;

void go(int num,int index,int plcnt,int micnt,int mucnt,int dicnt,int cnt)
{
//	printf("%d %d %d %d %d %d %d\n",num,index,plcnt,micnt,mucnt,dicnt,cnt);
	if(cnt==n)
	{	
		maxans=max(num,maxans);
		minans=min(num,minans);	
	
	}
	
	
	
	if(plcnt>0)
	{	
		
		go(num+a[cnt],index+1,plcnt-1,micnt,mucnt,dicnt,cnt+1);
	
	}
	
	if(micnt>0)
	{
		go(num-a[cnt],index+1,plcnt,micnt-1,mucnt,dicnt,cnt+1);
	}
	
	if(mucnt>0)
	{
		go(num*a[cnt],index+1,plcnt,micnt,mucnt-1,dicnt,cnt+1);
	}
	
	if(dicnt>0)
	{	
		go(num/a[cnt],index,plcnt,micnt,mucnt,dicnt-1,cnt+1);
	}
	
	
	
	
}


int main(int argc, char** argv) {
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>pl>>mi>>mu>>di;
	
	go(a[0],0,pl,mi,mu,di,1);

	printf("%d\n",maxans);
	printf("%d\n",minans);
	return 0;
}

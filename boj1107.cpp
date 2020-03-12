#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int btn[11];
int cnt(int k)
{
	int c=0;
	if(k==0)
		{
			if(btn[k]==1)
				return 0;
			else
				return 1;
		}
	while(k)
	{
		if(btn[k%10]==1)
			return 0;
		
		c++;
		k/=10;	
	}
	return c;
}
int main(int argc, char** argv) {
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int sw;
		cin>>sw;
		btn[sw]=1;
	}
	int cur=100;
	
	int ans=999999999;
	for(int i=0;i<=1000000;i++)
	{
		int k=cnt(i);
		if(k)
		{
			k+=abs(n-i);
			ans=min(k,ans);
		}
	}
	ans=min(ans,abs(n-100));
//	ans=min(n+1,ans);
	printf("%d",ans);
	return 0;
}

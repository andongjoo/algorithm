#include <iostream>
using namespace std;
int a[1000001];

int main(int argc, char** argv) {

	int n,m;
	cin>>n>>m;
	for(int i=2;i<=1000000;i++)
	{
		a[i]=i;
	}
	for(int i=2;(i*i)<=1000000;i++)
	{
	
		if(a[i]==0)
			continue;	
		for(int j=i+i;j<=1000000;j+=i)
		{
			
				a[j]=0;	
				
		}
	}
	
	for(int i=n;i<=m;i++)
	{
		if(a[i]!=0)
		 printf("%d\n",a[i]);
	}

	return 0;
}

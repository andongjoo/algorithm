#include <iostream>
#include <algorithm>
using namespace std;

int a[1000001];

int main(int argc, char** argv) {
	
    ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	
	for(int i=2;i<=1000000;i++)
		a[i]=i;
	for(int i=2;(i*i)<=1000000;i++)
	{
		if(!a[i])
			continue;
		for(int j=i+i;j<=1000000;j+=i)
		{
			a[j]=0;
		}
	}
	
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		int b_a=-1;
		int n1=0,n2=0;
		for(int i=3;i<=n;i+=2)
		{
			int j=n-i;
			if(!a[i])
				continue;
			if(!a[j])
				continue;
				
//				printf("%d %d\n",a[i],a[j]);
				
			if(i>j)
			{
				break;
			}
				
			if(a[i]+a[j]==n)
			{
				if(b_a<j-i)
				{
						b_a=j-i;
						n1=i;
						n2=j;
						break;
				}
			}
			
		}	
		if(b_a!=-1)
			printf("%d = %d + %d\n",n,n1,n2);
		else
			printf("Goldbach's conjecture is wrong.\n");
		
	}
	

	return 0;
}

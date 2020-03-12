#include <iostream>
#include <queue>
using namespace std;
int prime[10000];
int check[10000];
int main(int argc, char** argv) {
	for(int i=2;i<10000;i++)
	{
		prime[i]=i;
	}
	for(int i=2;i<10000;i++)
	{
		if(prime[i]==0)
			continue;
			
		for(int j=i+i;j<10000;j+=i)
		{
			prime[j]=0;
		}
	}
//	for(int i=0;i<=1000;i++)
//		if(prime[i])
//			printf("%d ",i);
//		
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
	
		queue<int> q;
		q.push(a);
		q.push(0);
//		printf("\n");
		while(!q.empty())
		{
			a=q.front();
//			printf("%d ",a);
			q.pop();
			int time=q.front();
			q.pop();
			if(a==b)
			{
				printf("%d\n",time);
				break;
			}	
			
			for(int i=1000;i<=9999;i++)
			{
				if(!prime[i])	
					continue;
				
				int temp=i;
				int y=temp%10;
				temp/=10; 
				int b=temp%10;
				temp/=10; 
				int c=temp%10;
				temp/=10; 
				int d=temp%10;
				
				temp=a;
				int p=temp%10;
				temp/=10; 
				int z=temp%10;
				temp/=10; 
				int w=temp%10;
				temp/=10; 
				int r=temp%10;
				int cnt=0;	
				if(y==p)
				{
					cnt++;
				}
				if(b==z)
				{
					cnt++;
				}
				if(c==w)
				{cnt++;
				}
				if(d==r)
				{
					cnt++;
				}
				
				if(cnt==3 && check[i]==0)
				{
					check[i]=1;
					
					q.push(i);
					q.push(time+1);
				}
				
				
			}
		}		
		while(!q.empty())
			q.pop();
		for(int i=1000;i<=9999;i++)
		{
			check[i]=0;
		}
	}

	return 0;
}

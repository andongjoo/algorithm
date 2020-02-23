#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=30;
int t[MAX]={0};
int p[MAX]={0};
int dp[MAX]={0};
int n;

int main(int argc, char** argv) 
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>t[i]>>p[i];
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if((j+t[j])<= i)
			dp[i]=max(dp[j]+p[j],dp[i]);
		
		}
	}	
	
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dp[i]);
	}
	
	
	return 0;
}

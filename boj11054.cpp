#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int dp2[1001];
int a[1001];
int n;
int main(int argc, char** argv) {
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
		
	}
	
	for(int i=n-1;i>=0;i--)
	{
		dp2[i]=1;
		for(int j=n-1;j>i;j--)
			{
				if(a[i]>a[j] && dp2[i]<dp2[j]+1)
					dp2[i]=dp2[j]+1;
			}
	}
	
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=max(sum,dp[i]+dp2[i]-1);
			}		
		printf("%d",sum);
	return 0;
}

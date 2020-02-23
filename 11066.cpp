#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX=501;
int a[MAX]={0};
int n;
int dp[MAX][MAX]={0};
int sum[MAX]={0};

int get_sum(int s,int e)
{
	if(dp[s][e]!=1999999999)
		return dp[s][e];
		
	if(s+1==e)
	{
		return dp[s][e]=a[e]+a[s];
	}
	
	if(s==e)
		return dp[s][e]=0;
	
	for(int mid=s;mid<=e;mid++)
	{
		int leftsum=get_sum(s,mid);
		int rightsum=get_sum(mid+1,e);
		dp[s][e]= min (dp[s][e],leftsum+rightsum);
		
	}
		dp[s][e]+= (sum[e]-sum[s-1]);
		return dp[s][e];
	
}

int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum[i]=a[i];
		}
		
		for(int i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+a[i];
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i][j]=1999999999;
			}
		}
		
		int ans=get_sum(0,n-1);
		printf("%d\n",ans);
		
		
		
	}


	return 0;
}

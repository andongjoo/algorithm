#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
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
			if(a[i]<a[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
		
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}

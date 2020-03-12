#include <iostream>
#include <algorithm>
using namespace std;

int a[5];
int m[13];
int tc;
int ans;
int dp[13];
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	
	cin>>tc;

	for(int t=1;t<=tc;t++)
	{
		for(int i=1;i<=4;i++)		
			cin>>a[i];
			
		for(int i=1;i<=12;i++)
			cin>>m[i];
		
			
		for(int i=0;i<=12;i++)
			dp[i]=0;
		
			
		ans=0;
		dp[1]=min(a[1]*m[1],a[2]);
		dp[2]=min(dp[1]+a[1]*m[2],dp[1]+a[2]);
		for(int i=3;i<=12;i++)
		{
				dp[i]=min(dp[i-1]+m[i]*a[1],dp[i-1]+a[2]);
				dp[i]=min(dp[i],dp[i-3]+a[3]);
		}
		ans=min(a[4],dp[12]);
		printf("#%d %d\n",t,ans);
	}


	return 0;
}

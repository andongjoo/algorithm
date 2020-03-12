#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int dp[10001];
int main(int argc, char** argv) {

		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
				cin>>a[i];
				dp[i]=0;
		}
			
		dp[1]=a[1];
		dp[2]=a[1]+a[2];
		for(int i=3;i<=n;i++)
		{
			dp[i]= max(dp[i-2]+a[i],dp[i-1]);
			dp[i]=max(dp[i],a[i]+a[i-1]+dp[i-3]);
		}

		cout<<dp[n];

	return 0;
}

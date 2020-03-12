#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[10001];
int dp[10001];

int main(int argc, char** argv) {

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0]=a[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i]=max(dp[i],dp[i-j]+a[j]);
		}
	}
	printf("%d",dp[n]);
	
	return 0;
}

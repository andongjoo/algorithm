#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=100001;
int a[MAX];
int dp[MAX];
int n;
int main(int argc, char** argv) {
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		dp[i]=i;
		for(int j=1;j*j<=i;j++)
		{
			dp[i]=min(dp[i],dp[i-j*j]+1);
		}
	}

	printf("%d",dp[n]);
	return 0;
}

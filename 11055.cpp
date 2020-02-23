#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1001;
int a[MAX];
int dp[MAX];
int n;
int ans=0;
int main(int argc, char** argv) {

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=a[i];
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
				if(dp[i]<dp[j]+a[i])
					dp[i]=dp[j]+a[i];
		}
		
	}
	int m=0;
	for(int i=0;i<n;i++)
		m=max(m,dp[i]);
	printf("%d",m);
	return 0;
}

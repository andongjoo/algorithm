#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=100001;
int a[MAX];
int dp[MAX];
int n;
int main(int argc, char** argv) {
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
			cin>>a[i];
	}
	dp[0]=a[0];
	int sum=0;
	for(int i=1;i<n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]+a[i]);
		sum=max(sum,dp[i]);
	}
	
	printf("%d",sum);
	
	
	
	return 0;
}

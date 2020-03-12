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
	dp[1]=a[0]+a[1];
	dp[2]=max(a[0]+a[1],a[1]+a[2]);
	for(int i=2;i<n;i++)
	{
		dp[i]=max(dp[i-2]+a[i],dp[i-3]+a[i]+a[i-1]);
	}
	printf("%d",dp[n-1]);
	
	return 0;
}

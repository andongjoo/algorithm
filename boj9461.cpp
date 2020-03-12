#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1001;
long long dp[MAX];
int n;
int main(int argc, char** argv) {
	
	cin>>n;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	
	for(int i=6;i<=100;i++)
	{
		dp[i]=dp[i-5]+dp[i-1];
	}
	
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		printf("%lld\n",dp[t]);
			
	}
	
	return 0;
}

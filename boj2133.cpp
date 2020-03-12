#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=100001;
int dp[MAX];
int n;
int main(int argc, char** argv) {
	
	cin>>n;
	dp[0]=1;
	dp[2]=3;
	
	
	for(int i=4;i<=n;i+=2)
	{
		dp[i]=dp[i-2]*3;
	
		for(int j=4;j<=i;j+=2)
			dp[i]+=dp[i-j]*2;
	}
	
	
	
	
	
	
	
	
	printf("%d",dp[n]);
	return 0;
}

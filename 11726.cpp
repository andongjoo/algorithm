#include <iostream>
using namespace std;
int dp[1001];

int go(int n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else if (dp[n]!=0)
		return dp[n]%10007;
	else{
		dp[n]=go(n-1)+go(n-2);
		return dp[n]%10007;
	}
	
}
int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	dp[1]=1;
	dp[2]=2;
	int ans=go(n);
	printf("%d\n",ans);
//	for(int i=0;i<n;i++)
//	{
//		printf("%d ",dp[i]);
//	}
	return 0;
}

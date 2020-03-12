#include <iostream>
using namespace std;

int n;
int dp[100];

int main(int argc, char** argv) {

	int test;
	cin>>test;
	for(int t=0;t<test;t++)
	{
		cin>>n;	
		for(int i=0;i<100;i++)
			dp[i]=0;
		
		dp[1]=1;
		dp[2]=2;
		dp[3]=4;
		
		for(int i=4;i<=n;i++)
		{
			dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
		}
		
		printf("%d\n",dp[n]);
	}
	
	
	
	
	return 0;
}

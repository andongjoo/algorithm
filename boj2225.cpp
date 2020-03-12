#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=201;
const int MOD=1000000000;
long long int dp[MAX][MAX];

int n,k;
int main(int argc, char** argv) {
	
	cin>> n>>k;
	for(int i=0;i<=200;i++)
	{
		dp[1][i]=1;
	}
	
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int l=0;l<=j;l++)
			{
				dp[i][j]+=dp[i-1][j-l];
				dp[i][j]%=MOD;		
			}
		}		
	}
	printf("%lld",dp[k][n]);
	
	return 0;
}

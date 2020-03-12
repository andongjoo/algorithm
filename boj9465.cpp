#include <iostream>
#include <algorithm>
using namespace std;

int test;
int n;
int map[2][101];
long long dp[2][101];
int main(int argc, char** argv) {

	cin>>test;
	for(int t=0;t<test;t++)
	{
		long long res=0;
//		for(int i=0;i<101;i++)
//		{
//			dp[i][0]=0;
//			dp[i][1]=0;
//			map[i][0]=0;
//			map[i][1]=0;
//		}
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>map[0][i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>map[1][i];
		}

		

		
		dp[0][1]=map[0][1];
		dp[1][1]=map[1][1];
		
		dp[0][2]= map[1][1]+map[0][2];
		dp[1][2]=map[0][1]+map[1][2];
		for(int i=3;i<=n;i++)
		{
			
			dp[0][i]=max(dp[1][i-1],dp[1][i-2])+map[0][i];
			dp[1][i]=max(dp[0][i-1],dp[0][i-2])+map[1][i];
		}
		
		
		cout<<max(dp[0][n],dp[1][n])<<endl;
	}
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[30][30];
int tc;

int get(int n,int m)
{
	if(n==m || n==0)
		return 1;
		
	if(dp[n][m])
		return dp[n][m];
	
	
	return dp[n][m]=get(n-1,m-1)+get(n,m-1);
	
}


int main(int argc, char** argv) {
	cin>>tc;
	
	for(int t=0;t<tc;t++)
	{
		memset(dp,0,sizeof(dp));
		
		
		int a,b;
		cin>>a>>b;
		
		int ret=get(a,b);
		printf("%d\n",ret);
		
		
	}
	
	return 0;
}

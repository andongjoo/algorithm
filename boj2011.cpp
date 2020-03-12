#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD=1000000;
int dp[5001];
char str[5001];
int a[5001];

int main(int argc, char** argv) {
	cin>>str;
	
	int n=strlen(str);
	for(int i=1;i<=n;i++)
	{
		a[i]=str[i-1]-'0';
	}
	
	
	
	if(n==1 && str[0]=='0')
	{
		printf("0");
		return 0;
	}
	dp[0]=1;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=1 && a[i]<=9)
		{
			dp[i]= (dp[i-1]+dp[i])%MOD;
		}
	
		if(i!=1)
		{
			
			int temp=a[i]+a[i-1]*10;
			if(temp>=10 && temp<=26)
			{
				dp[i]=(dp[i-2]+dp[i])%MOD;
			}
			
			
		}
	
	}
	
	printf("%d",dp[n]);
		
		
		
	
	return 0;
}

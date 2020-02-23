#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX=1001;
int dp[MAX][MAX]={0,};
int main(int argc, char** argv) {
	string str1;
	string str2;

	cin>>str1>>str2;
	
	for(int i=1;i<=str1.length();i++)
	{
		for(int j=1;j<=str2.length();j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	printf("%d",dp[str1.length()][str2.length()]);
	
	
	
	
	
	
	return 0;
}

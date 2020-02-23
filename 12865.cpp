#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=101;

int n,k;
int w[MAX]={0};
int v[MAX]={0};
int dp[100001]={0};


int main(int argc, char** argv) {
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=k;j>=1;j--)
		{
			if(w[i]<=j)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
	}
	printf("%d",dp[k]);
	return 0;
}

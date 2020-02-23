#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=501;
int dp[MAX][MAX]={0};
pair<int,int> a[MAX];
int n,r,c; 

int sum(int s,int e)
{
	if(s==e)
		return 0;	
	
	if(s+1==e)
	{
		return dp[s][e]=a[s].first*a[s].second*a[e].second;
	}
	
	if(dp[s][e]!=1999999999)
		return dp[s][e];
	
	for(int mid=s;mid<e;mid++)
	{
		int leftsum=sum(s,mid);
		int rightsum=sum(mid+1,e);
		dp[s][e]=min(dp[s][e],leftsum+rightsum+a[s].first*a[mid].second*a[e].second);
	}
	
	return dp[s][e];
	
}


int main(int argc, char** argv) {
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i][j]=1999999999;
			}
		}
		
	
	int ans=sum(0,n-1);	
	printf("%d",ans);
	return 0;
}

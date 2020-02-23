#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=101;

int dp[MAX]={0};
int n;
int number=0;
int ans=0;
typedef pair<int,int> row[MAX];

int main(int argc, char** argv) {
	cin>>n;
	row r;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		r[i].first=a;
		r[i].second=b;
	}
	
	sort(r,r+n);
	for(int i=0;i<n;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			
			if(r[j].second<r[i].second )
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
			
			
			
		}
		ans=max(ans,dp[i]);
	
	}
	printf("%d",n-ans);
	return 0;
}

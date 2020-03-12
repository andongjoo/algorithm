#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=16;
int a[MAX][MAX];
int check[MAX];
int n;
int tc;
int ans;
void dfs(int index,int cnt)
{
	if( n/2==cnt && index==n)
	{
		int sum1=0;
		int sum2=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(i==j)
					continue;
				if(check[i] && check[j])
				{
					sum1+=a[i][j]+a[j][i];
				}
				
				if(!check[j] && !check[i])
				{
					sum2+=a[j][i]+a[i][j];
				}
				
				
			}
		}
		ans=min(ans,abs(sum1-sum2));
		
		return;
	}
	
	if(index==n)
		return;
	
	check[index]=1;
	dfs(index+1,cnt+1);
	check[index]=0;
	dfs(index+1,cnt);
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		ans=987987987;
	
		
		for(int i=0;i<MAX;i++)
			check[i]=0;
		
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		

	
		dfs(0,0);
		
		
		
		
		printf("#%d %d\n",t,ans);
	}
	



	return 0;
}

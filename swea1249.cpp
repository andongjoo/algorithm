#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int MAX=101;
int tc;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int ans;
int n;
int map[MAX][MAX];
int dp[MAX][MAX];

int dfs()
{
	dp[0][0]=0;
	queue<pair<int,pair<int,int> > > q;
	q.push({0,{0,0}});
	
	while(!q.empty())
	{
		int cost=q.front().first;
		int x=q.front().second.first;
		int y=q.front().second.second;
		q.pop();
		
		if(dp[x][y]==987987987)
			dp[x][y]=cost;
		
		for(int i=0;i<4;i++)
		{
			
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(ny>=n || nx>= n || nx<0 || ny<0)
				continue;
				
			if(dp[nx][ny]>map[nx][ny]+dp[x][y])
			{
				dp[nx][ny]=map[nx][ny]+dp[x][y];
				q.push({dp[nx][ny],{nx,ny}});
			}
			
			
		}
	
	}
	
	return dp[n-1][n-1];
}


int main(int argc, char** argv) {
//	cin.tie(0);
//	cout.tie(0);
	
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%1d",&map[i][j]);
				dp[i][j]=987987987;
			}
		}
		
		
		ans=dfs();
		
		
			
		printf("#%d %d\n",t,ans);
	}	

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int MAX=100+1;
const int MAX_LEN=80+1;
int n,m,k;
char a[MAX][MAX];
int str_len=0;
int dp[MAX][MAX][MAX_LEN];
bool visit[MAX][MAX];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
string str="";	
int ans=0;
int dfs(int r,int c,int idx)
{
	
	if(dp[r][c][idx]!=-1)
		return dp[r][c][idx];
		
	if(idx>=str_len)
		return 1;
	
	dp[r][c][idx]=0;
	
	
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=k;j++)
		{
		
			int ny=r+dy[i]*j;
			int nx=c+dx[i]*j;
			
			if(ny>=n || nx>=m || ny<0 || nx<0)
				continue;
			if(a[ny][nx]!=str[idx])
				continue;
			
				dp[r][c][idx]+=dfs(ny,nx,idx+1);
		}
	}
		
	return dp[r][c][idx];	
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>m>>k;	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	cin>>str;
	ans=0;
	str_len=str.length();
    memset(dp, -1, sizeof(dp));


	char f=str[0];
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			if(a[i][j]==f)
			{
				ans+=	dfs(i,j,1);		
			}
		}
	}
	
	printf("%d\n",ans);
	
	
	
	return 0;
}

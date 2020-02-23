#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=501;
int n,m;


int map[MAX][MAX]={0,};
int dp[MAX][MAX]={0};
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int check[MAX][MAX]={0};
int result=0;

int go(int y,int x)
{
	
	if(y==n-1 && x==m-1)
	{
		return 1;
	}
	
	if(check[y][x]==1)
		return dp[y][x];
		
	if(n==0 && m==0)
		return 1;
		
	check[y][x]=1;
	
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(0<=ny && 0<=nx && nx<m && ny<n && map[y][x]>map[ny][nx])
		{
			dp[y][x]+=go(ny,nx);
			
		}
	}

	return dp[y][x];	
}


int main(int argc, char** argv) {

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			
		}
	}
	
	printf("%d",go(0,0));

	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=10;
int map[MAX][MAX]={0,};
int map2[MAX][MAX]={0};
int n,m;
int cnt=0;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int checkwall[MAX][MAX]={0};
int check[MAX][MAX]={0};

void area()
{
	int a=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map2[i][j]==0)
			{
				a++;	
			}
		}
	}
	
	cnt=max(a,cnt);
}

void dfs(int y,int x)
{
	
	check[y][x]=1;
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(map2[ny][nx]==0 && check[ny][nx]==0 && nx<m && ny<n && 0<=nx && 0<=ny) 
		{
			dfs(ny,nx);
		}
		
	}
	
}


void spread()
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map2[i][j]==2 && check[i][j]==0)
				dfs(i,j);
		}
	}
	
	area();
}

void wall(int index,int wallcnt)
{
	
	if(wallcnt>=3)
	{
		spread();
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==0 && checkwall[i][j]==0)
			{
				checkwall[i][j]=1;
				map2[i][j]=1;
				wall(index+1,wallcnt+1);
				checkwall[i][j]=0;
			}
			
		}
	}
	
	
}



int main(int argc, char** argv) {
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			map2[i][j]=map[i][j];
		}
	}

	wall(0,0);
	

	printf("%d",cnt);


	return 0;
}

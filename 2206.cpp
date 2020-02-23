#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX=1001;
int result=99999999;
int check2[MAX][MAX]={0};
int check[MAX][MAX]={0};
int cnt[MAX][MAX]={0};
int cnt2[MAX][MAX]={0};

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

char map[MAX][MAX]={0};

int n,m;

void bfs(int x,int y)
{
	queue <int> q;
	q.push(x);
	q.push(y);
	check[x][y]=1;
	cnt[x][y]=1;
	
	while(!q.empty())
	{
		int cur_x=q.front();
		q.pop();
		int cur_y=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
		
			int ny=cur_y+dy[i];
			int nx=cur_x+dx[i];		
			
			if(1<=nx && 1<=ny &&  nx<=n && ny<=m &&check[nx][ny]==0 && map[nx][ny]==0)
			{
				check[nx][ny]=1;
				cnt[nx][ny]=cnt[cur_x][cur_y]+1;
				q.push(nx);
				q.push(ny);
				
			}
	
	
	
		}
	}
}

void bfs2(int x,int y)
{
	queue <int>q;
	q.push(x);
	q.push(y);
	check2[x][y]=1;
	cnt2[x][y]=1;
	
	while(!q.empty())
	{
		int cur_x=q.front();
		q.pop();
		int cur_y=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
		
			int ny=cur_y+dy[i];
			int nx=cur_x+dx[i];		
			
			if(1<=nx && 1<=ny &&  nx<=n && ny<=m &&  check2[nx][ny]==0 && map[nx][ny]==0)
			{
				check2[nx][ny]=1;
				cnt2[nx][ny]=cnt2[cur_x][cur_y]+1;
				q.push(nx);
				q.push(ny);
			}
	
	
	
		}
	}
}

int main(int argc, char** argv) {
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
			scanf("%s",map[i]+1);
		
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			map[i][j]-='0';
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",map[i][j]);
//		}printf("\n");
//		
//	}printf("\n");
	
	bfs(1,1);
	bfs2(n,m);

	if(cnt[n][m]!=0)
	{
		result=min(cnt[n][m],result);
	}
	if(cnt2[1][1]!=0)
	{
		result=min(cnt2[1][1],result);
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",cnt[i][j]);
//		}printf("\n");
//		
//	}printf("\n");
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",cnt2[i][j]);
//		}printf("\n");
//		
//	}printf("\n");
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]==1)
			{
				
				for(int k=0;k<4;k++)
				{
					int ny=j+dy[k];
					int nx=i+dx[k];
					
					for(int z=0;z<4;z++)
					{
						int zy=j+dy[z];
						int zx=i+dx[z];
						
						if(1<=zy && 1<=zx && 1<=ny && 1<=nx &&  zy<=m && ny <=m && zx <=n &&nx<=n &&
						zy!=ny || zx!=nx )
						{
							if(cnt[nx][ny]!=0 && cnt2[zx][zy]!=0)
								result=min(result,cnt[nx][ny]+cnt2[zx][zy]+1);
							
//							printf("%d %d   %d %d   %d    %d  %d %d \n",nx,ny,zx,zy,result,cnt[nx][ny]+cnt2[zx][zy]+1,cnt[nx][ny],cnt2[zx][zy]);
						}
						
						
					}
					
					
				}
				
				
			}
			
		}
	}
	
	if(result==99999999)
		printf("-1");
	else
		printf("%d",result);
	
	
	return 0;
}

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int map[101][101];
int group[101][101];
int n;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int cnt[101][101];
int visit[101][101];

void make_group(int r,int c,int index)
{
	queue<pair<int,int> > q;
	group[r][c]=index;
	q.push(make_pair(r,c));
	
	while(!q.empty())
	{
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			
			if( nx<0 || ny <0 || nx>=n || ny>=n)
				continue;
			
			if(group[ny][nx]!=0)
				continue;
				
			if(group[ny][nx]==0 && map[ny][nx]==1)
			{
				group[ny][nx]=index;
				q.push(make_pair(ny,nx));
			}
		}
		
		
	}
		
	
}
int ans=987987987;
void bfs(int r,int c,int index)
{
	visit[r][c]==1;
//	printf("start: %d,%d\n",r,c);
	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	
	while(!q.empty())
	{
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if( nx<0 || ny <0 || nx>=n || ny>=n)
				continue;
			
			if(map[ny][nx]==0 && !visit[ny][nx])
			{
			
				visit[ny][nx]=1;
				q.push(make_pair(ny,nx));
				cnt[ny][nx]=cnt[y][x]+1;
//				printf("%d %d cnt:%d\n",y,x,cnt[ny][nx]);
				
			}
			else if(map[ny][nx]!=0 && group[ny][nx]!=index)
			{
				visit[ny][nx]=1;
				ans=min(cnt[y][x],ans);
//				printf("end: %d,%d  %d \n",ny,nx,ans);
			}			
			
		}
		
		
	}
	
	
}


int main(int argc, char** argv) {
	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
			
	queue<pair<int,int> > q;
	int index=1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==1 && group[i][j]==0)	
			{
				make_group(i,j,index++);
			}		
		}	
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==1 && group[i][j]!=0)	
			{
				
				for(int k=0;k<n;k++)
				{
					for(int z=0;z<n;z++)
					{
						visit[k][z]=0;
						cnt[k][z]=0;
					}
				}
				bfs(i,j,group[i][j]);
				
			}		
		}	
	}
	
	
	printf("%d",ans);
	
	return 0;
}

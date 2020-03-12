#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX=50;
int a[MAX][MAX];
int visit[MAX][MAX];
int n,m,r,c,l;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

int ans;
queue<pair<int,int> >q;
void bfs(int y,int x)
{
	visit[y][x]=1;
	q.push(make_pair(y,x));
	
	while(!q.empty())
	{
		int cur_y=q.front().first;		
		int cur_x=q.front().second;
//		printf("%d %d\n",cur_y,cur_x);
		q.pop();
		for(int i=0;i<4;i++)
		{
			int ny=cur_y+dy[i];
			int nx=cur_x+dx[i];
			
			if(ny<0 || nx<0 || ny>=n || nx>=m)
				continue;
			if(visit[ny][nx])
				continue;
				
			if(a[cur_y][cur_x]==1)
			{
				
				if ( ny==cur_y+1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==4 ||a[ny][nx]==7 )
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				
				}else if (ny==cur_y-1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==6 ||a[ny][nx]==5)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}else if (ny==cur_y&& nx==cur_x-1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==4 ||a[ny][nx]==5)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}else if (ny==cur_y && nx==cur_x+1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==6 ||a[ny][nx]==7)
					{
						visit[ny][nx]=visit[cur_y][cur_x]+1;
						q.push(make_pair(ny,nx));
					}
				}
			}else if (a[cur_y][cur_x]==2)
			{
				
				if ( ny==cur_y+1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==4 ||a[ny][nx]==7 )
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				
				}else if (ny==cur_y-1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==6 ||a[ny][nx]==5)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}
				
			}else if (a[cur_y][cur_x]==3)
			{
				if ( ny==cur_y && nx==cur_x-1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==5 ||a[ny][nx]==4 )
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				
				}else if (ny==cur_y && nx==cur_x+1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==6 ||a[ny][nx]==7)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}
				
			}else if (a[cur_y][cur_x]==4)
			{
				if ( ny==cur_y-1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==5 ||a[ny][nx]==6 )
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				
				}else if (ny==cur_y && nx==cur_x+1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==6 ||a[ny][nx]==7)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}
				
				
			}else if (a[cur_y][cur_x]==5)
			{
				
				if ( ny==cur_y && nx==cur_x+1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==7  ||a[ny][nx]==6 )
					{
						visit[ny][nx]=visit[cur_y][cur_x]+1;
						q.push(make_pair(ny,nx));
					}
				
				}else if (ny==cur_y+1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==4 ||a[ny][nx]==7)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}
				
			}else if (a[cur_y][cur_x]==6)
			{
				if ( ny==cur_y && nx==cur_x-1)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 3 ||a[ny][nx]==4 ||a[ny][nx]==5)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				
				}else if (ny==cur_y+1 && nx==cur_x)
				{
					if(a[ny][nx]==1 || a[ny][nx]== 2 ||a[ny][nx]==4 ||a[ny][nx]==7)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}
				
			}else if (a[cur_y][cur_x]==7)
			{
				if ( ny==cur_y-1 && nx==cur_x)
				{
					if(a[ny][nx]==6 || a[ny][nx]== 1 ||a[ny][nx]==5 ||a[ny][nx]==2)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}else if (ny==cur_y && nx==cur_x-1)
				{
					if(a[ny][nx]==1 || a[ny][nx]==3 ||a[ny][nx]==4 ||a[ny][nx]==5)
					{
						q.push(make_pair(ny,nx));
						visit[ny][nx]=visit[cur_y][cur_x]+1;
					}
				}
				
			}
			
			
		}
		
	}
	
	
}


int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int tc;
	cin>>tc;
	for(int k=0;k<tc;k++)
	{
		cin>>n>>m>>r>>c>>l;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				visit[i][j]=0;
			}
		}
		
		bfs(r,c);	
		ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(visit[i][j]>=1  && visit[i][j]<=l)
				{
					ans++;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%d ",visit[i][j]);
			}printf("\n");
		}
		
		printf("#%d %d\n",k+1,ans);
	}
	

	return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX=9;

int map[MAX][MAX];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visit[MAX][MAX];
int n,m;
int ans=0;
int c;
int solve()
{
	queue<pair<int,int> > q;
	
//	printf("%d",c++);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==2)
			{
				visit[i][j]=true;
				q.push({i,j});
			}
		}
	}
	
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
//		printf("%d %d\n",x,y);
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
//			printf("%d %d\n",nx,ny);
				
			if(nx>=n || ny>=m || nx<0 || ny<0)
				continue;
				
			if(visit[nx][ny])
				continue;
			
			if(map[nx][ny]==0)
			{
				visit[nx][ny]=true;
				q.push({nx,ny});
			}
			
		}
		
	}
	int res=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visit[i][j] && map[i][j]==0)
				res++;
		}
	}

		
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			printf("%d ",map[i][j]);
//		}printf("\n");
//	}printf("\n");

	return res;
	
}

void go(int cnt,int r,int c)
{
	
	if (cnt==3)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				visit[i][j]=0;
		
		int res=solve();
		ans=max(ans,res);
		return;
	}
	
	for(int i=r;i<n;i++)
	{
		int k=0;
		if(i==r)
			k=c;
		
		for(int j=k;j<m;j++)
		{
			if(map[i][j]==0)
			{
				map[i][j]=1;
				go(cnt+1,i,j+1);
				map[i][j]=0;
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
		}
	}
	
	go(0,0,0);
	printf("%d\n",ans);
	return 0;
}

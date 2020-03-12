#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool visit[50+1][50+1];
int map[50+1][50+1];
int w,h;
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

queue<pair<int,int>> q;

void bfs(int r,int l)
{
	q.push(make_pair(r,l));
	visit[r][l]=true;	
	while(!q.empty())
	{
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		
		for(int i=0;i<8;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(ny<0 || ny>=h || nx<0 || nx>=w)
				continue;
			
			if(visit[ny][nx])
				continue;
			
			if(map[ny][nx]==1)
			{
				q.push(make_pair(ny,nx));
				visit[ny][nx]=1;
			}
		}
		
		
	}
	
	
}


int main(int argc, char** argv) {
	
	
	while(1)
	{
		cin>>w>>h;
		int cnt=0;
		if(w==0 && h==0)
			break;
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
					cin>>map[i][j];
					visit[i][j]=0;
			}
		}
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(!visit[i][j] && map[i][j]==1)
				{
						bfs(i,j);
						cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	
	return 0;
}

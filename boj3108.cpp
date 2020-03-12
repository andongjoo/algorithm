#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX=2000+1;
int n;
int cnt;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs(int r,int c)
{
	visit[r][c]=1;
	queue<int> q;
	q.push(r);
	q.push(c);
	
	while(!q.empty())
	{
		int y=q.front();q.pop();
		int x=q.front();q.pop();
		map[y][x]=2;
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(ny>=MAX || nx>=MAX || nx<0 || ny<0)
				continue;
				
			if(!visit[ny][nx] && map[ny][nx]==1)
			{
				q.push(ny);
				q.push(nx);
				visit[ny][nx]=1;
			}
		}
		
	}
	
}

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;
 
		for(int j=y1;j<=y2;j++)
		{
			map[j][x1]=1;
			map[j][x2]=1;
		}
		
		for(int j=x1;j<=x2;j++)
		{
			map[y1][j]=1;
			map[y2][j]=1;
		}
		
	}
	
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			if(visit[i][j]==false && map[i][j]==1)
			{
				cnt++;
				bfs(i,j);
			}
		}
	}
	if(map[1000][1000]==2)
		cnt--;
	printf("%d",cnt);
	
	return 0;
}

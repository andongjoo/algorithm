#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX=1001;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int cnt[MAX][MAX]={0};
int visit[MAX][MAX]={0};
int map[MAX][MAX]={0};
int x,y,w,h;
queue<int> q;

int main(int argc, char** argv) {

	cin>>x>>y>>w>>h;
	q.push(x);
	q.push(y);
	
	
	while(!q.empty())	
	{
		
		visit[x][y]=1;
		int front_x=q.front();
		q.pop();
		int front_y=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nx=dx[i]+front_x;
			int ny=dy[i]+front_y;
			
			if(0<=nx && nx<=w && 0<=ny && ny<=h && !visit[nx][ny] )
			{
				q.push(nx);
				q.push(ny);
				visit[nx][ny]=1;
				cnt[nx][ny]=cnt[front_x][front_y]+1;
			}
			
			
			
		}
		
		
		
	}

	int ans=999999999;
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=h;j++)
		{
			if( i==0 || j==0 || i==w || j==h)
			{
				ans=min(ans,cnt[i][j]);
			}
			
			
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}

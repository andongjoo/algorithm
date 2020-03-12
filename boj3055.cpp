#include <iostream>
#include <queue>
using namespace std;
const int MAX=52;
int r,c;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

char map[MAX][MAX];
int water[MAX][MAX];
int cnt[MAX][MAX];
bool visit[MAX][MAX];
bool visit2[MAX][MAX];
queue<pair<int,int> >w;
queue<pair<int,int> >s; 
bool flag;
int main(int argc, char** argv) {
	
	cin>>r>>c;
	

	
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='*')
			{
				w.push({i,j});
				visit[i][j]=true;
			}
			if(map[i][j]=='S')
			{
				s.push({i,j});
				visit2[i][j]=true;	
			}
		}
	}
	
	while(!w.empty())
	{
		
		int x=w.front().first;
		int y=w.front().second;
//		printf("%d %d\n",x,y);
		w.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=r || ny>=c || nx<0 || ny<0)
				continue;
			if (visit[nx][ny] || map[nx][ny]=='X' ||map[nx][ny]=='D')
				continue;
				
			if((map[nx][ny]=='.' || map[nx][ny]=='S'))
			{
//				printf("%d %d \n",nx,ny);
				w.push({nx,ny});
				visit[nx][ny]=true;
				water[nx][ny]=water[x][y]+1;
			}
			
			
		}
		
	}
	
//	for(int i=0;i<r;i++)
//	{
//		for(int j=0;j<c;j++)
//		{
//			printf("%d ",water[i][j]);
//		}printf("\n");
//	}printf("\n");
//	
	while(!s.empty())
	{
		int x=s.front().first;
		int y=s.front().second;
		s.pop();
		
	
		
		
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			
			
			if(nx>=r || ny>=c || nx<0 || ny<0)
				continue;
				
			if (visit2[nx][ny] || map[nx][ny]=='X'||map[nx][ny]=='*')
				continue;
				
			if(map[nx][ny]=='D')
			{
			printf("%d",cnt[x][y]+1);
			return 0;	
			}
				
				if(0!=water[nx][ny] && cnt[x][y]+1>=water[nx][ny])
					continue;
					
				cnt[nx][ny]=cnt[x][y]+1;
				s.push({nx,ny});
				visit2[nx][ny]=true;
				
			
		}
		
	}
	
//	for(int i=0;i<r;i++)
//	{
//		for(int j=0;j<c;j++)
//		{
//			printf("%d ",cnt[i][j]);
//		}printf("\n");
//	}printf("\n");
	
//	for(int i=0;i<r;i++)
//	{
//		for(int j=0;j<c;j++)
//		{
//			printf("%c ",map[i][j]);
//		}printf("\n");
//	}
	printf("KAKTUS");
	return 0;
}

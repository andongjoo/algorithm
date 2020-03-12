#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int n,m;
const int MAX=11;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
char map[MAX][MAX];
int visit[MAX][MAX][MAX][MAX];
int ans=-1;

int bx,by,rx,ry;
int bfs(){
	
	visit[rx][ry][bx][by]=1;
	queue< pair<pair<int,int>, pair<int,int> > > q;
	q.push({{rx,ry},{bx,by}});
	int res=0;
	
	while(!q.empty())
	{
		int qs=q.size();
		
		while(qs--)
		{
			int x=q.front().first.first;
			int y=q.front().first.second;
			int z=q.front().second.first;
			int w=q.front().second.second;
			q.pop();
			
			
			if(map[x][y]=='O' && map[x][y]!=map[z][w])
				return res;
							
			for(int i=0;i<4;i++)
			{
				int nx=x;
				int ny=y;
				int nz=z;
				int nw=w;
				
				
				while(map[nx+dx[i]][ny+dy[i]]!='#' && map[nx][ny]!='O' )
				{
					nx+=dx[i];
					ny+=dy[i];
				}
				
				while(map[nz+dx[i]][nw+dy[i]]!='#'  && map[nz][nw]!='O')
				{
					nz+=dx[i];
					nw+=dy[i];
				}
		
				
				if(nx==nz && nw==ny)
				{
					if(map[nx][ny]=='O')
						continue;
					
					if(abs(nx-x)+abs(ny-y) < abs(nw-w)+abs(nz-z))
					{
						nw-=dy[i];
						nz-=dx[i];
					}else{
						nx-=dx[i];
						ny-=dy[i];						
					}
					
				}
		
				if(visit[nx][ny][nz][nw])
					continue;
		
				q.push({{nx,ny},{nz,nw}});
				visit[nx][ny][nz][nw]=1;
		
			}
			
		
		}
		if(res==10)
			return -1;
		
		res++;
		
	}
	
	return -1;
	

}


int main(int argc, char** argv) {
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='B')
			{
				bx=i,by=j;
			}
			if(map[i][j]=='R')
			{
				rx=i,ry=j;	
			}
		}
	}
	printf("%d\n",bfs());
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			printf("%c ",map[i][j]);	
//		}printf("\n");
//	}
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int MAX=51;
int r,c,t;
int map[MAX][MAX];
int tmpmap[MAX][MAX];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int oy;
queue<pair<int,int> > q;
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>r>>c>>t;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>map[i][j];
			tmpmap[i][j]=map[i][j];
		}
	}
	
	for(int k=0;k<t;k++)
	{
		
		for(int i=0;i<r-1;i++)
		{
			if(map[i][0]==-1)
			{
				oy=i;
				break;
			}				
			
		}
		
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				tmpmap[i][j]=0;
			}
		}
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(map[i][j]>0)
				{
					q.push(make_pair(i,j));
				}
				
			}
		}
		
		while(!q.empty())
		{
		
			int y=q.front().first;
			int x=q.front().second;
			q.pop();

			int value=map[y][x]/5;
			for(int j=0;j<4;j++)
			{
				int ny=y+dy[j];
				int nx=x+dx[j];
				
				if(ny>=r || nx>= c || ny<0 || nx<0)
					continue;
				
				if(map[ny][nx]==-1)
					continue;
				
				tmpmap[ny][nx]+=value;
				map[y][x]-=value;
				
			}
		}
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				map[i][j]+=tmpmap[i][j];
			}
		}
				
		
				for(int l=oy;l>=1;l--)
				{
						map[l][0]=map[l-1][0];
				}
				
				for(int l=oy;l<r-1;l++)
				{
						map[l][0]=map[l+1][0];
				}
					
				for(int l=0;l<c-1;l++)
				{
					map[0][l]=map[0][l+1];
					map[r-1][l]=map[r-1][l+1];
				}
					
						
				for(int l=0;l<=oy-1;l++)
				{
					map[l][c-1]=map[l+1][c-1];
				}
				
				for(int l=r-1;l>oy;l--)
				{
					map[l][c-1]=map[l-1][c-1];
				} 
				for(int l=c-1;l>1;l--)
				{
						map[oy][l]=map[oy][l-1];
						map[oy+1][l]=map[oy+1][l-1];
				}
					
				map[oy][1]=0;
				map[oy+1][1]=0;
				
				map[oy][0]=-1;
				map[oy+1][0]=-1;
					
					
//		printf("\n");
//		for(int i=0;i<r;i++)
//		{
//			for(int j=0;j<c;j++)
//			{
//				printf("%2d ",map[i][j]);
//			}	printf("\n");
//		}printf("\n");
	}
	int ans=0;
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(map[i][j]>0)
				ans+=map[i][j];
		}
	}
	
	printf("%d",ans);

	return 0;
}

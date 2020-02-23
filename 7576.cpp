#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_LE=1001;
queue<int> q;
int n,m;
int tomato[MAX_LE][MAX_LE]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int check[MAX_LE][MAX_LE]={0,};

void bfs()
{
	while(!q.empty())
	{
		int y = q.front();
		q.pop();
		int x= q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int yy=y+dy[i];	
			int xx=x+dx[i];
			
			if( 0<=yy && yy<n && 0<=xx && xx<m && check[yy][xx]==0 && tomato[yy][xx]==0)
			{
				q.push(yy);
				q.push(xx);
				check[yy][xx]=check[y][x]+1;
			}
			
		
		}		
			
	}	
	
	
	
	
}
 
int main(int argc, char** argv) {

	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>tomato[i][j];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(tomato[i][j]==1)
				{
					q.push(i);
					q.push(j);
				}
		}
	}
	
	bfs();
	int result=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			result=max(result,check[i][j]);
		}
	}
	
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if (tomato[i][j]==0 && check[i][j]==0 )
				{
					printf("-1");
					return 0;
						}		
			
		}
	}
	printf("%d",result);
	return 0;
}

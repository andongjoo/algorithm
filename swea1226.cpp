#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int ans;
char map[16][16];
bool check[16][16];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};


int tn;
queue<int> q;
	
int bfs(int r,int c)
{
	q.push(r);
	q.push(c);
	check[r][c]=true;
	
	while(!q.empty())
	{
		int y=q.front();
		q.pop();
		int x=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int ny=y+dy[i];
			int nx=x+dx[i];
			
			if(ny>=16 || nx>=16 || nx<0 || ny<0)
				continue;
			if(check[ny][nx]==true || map[ny][nx]==1)
				continue;
		
			if(map[ny][nx]==3)
			{
					return 1;
			}
			if(map[ny][nx]==0)
			{
				q.push(ny);
				q.push(nx);
				check[ny][nx]=true;
			}
			
		}
		
	}
		
	return 0;
}


int main(int argc, char** argv) {

	for(int t=1;t<=10;t++)
	{
		cin>>tn;
		ans=0;
		while (!q.empty()) q.pop();
		for(int i=0;i<16;i++)
		{
			scanf("%s",map[i]);
		}
		
		
		for(int i=0;i<16;i++)
		{
			for(int j=0;j<16;j++)
			{
				map[i][j]-='0';
				check[i][j]=false;
			}
		}
	
	
	
	
		for(int i=0;i<16;i++)
		{
			for(int j=0;j<16;j++)
			{
				if(map[i][j]==2)
				{
					ans=bfs(i,j);
				}
			}
		}
	
		printf("#%d %d\n",t,ans);
	}
	return 0;
}

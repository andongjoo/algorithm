
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
const int MAX=21;
int dy[]={1,1,-1,-1};
int dx[]={1,-1,-1,1};

int n;
int oy,ox;
int ans;
int a[MAX][MAX];
bool visit[101];
void dfs(int y,int x,int cnt,int dir)
{
	if(dir==3 && y==oy && x==ox)
	{
		ans=max(ans,cnt);
		return;	
	}


	
	
	for(int i=0;i<2;i++)
	{
		int ny,nx,nd;
		if(i==0)
		{
		
			nd=dir;
			ny=y+dy[dir];
			nx=x+dx[dir];
		}else {
			if(x==ox && y==oy)
				continue;
				
			if(dir==3)
				continue;
				
			 ny=y+dy[dir+1];
			 nx=x+dx[dir+1];
			nd=dir+1;
		}
		
		
		if(nx>=n || nx<0 || ny>=n || ny<0)
			continue;
			
		if(ny==oy && nx==ox)
		{
			dfs(ny,nx,cnt+1,nd);
			break;
		}	
			
			
		if(visit[a[ny][nx]]==false)
		{
			visit[a[ny][nx]]=true;
			dfs(ny,nx,cnt+1,nd);
			visit[a[ny][nx]]=false;
			
		}
		
		
	}
	
}


int main(int argc, char** argv){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int tc;
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		cin>>n;
	
		ans=-1;
		
		for(int i=0;i<101;i++)
			visit[i]=0;
			
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				
				visit[a[i][j]]=true;
				oy=i; ox=j;
				dfs(i,j,0,0);
				visit[a[i][j]]=false;
			}
		}
		
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=20+1;
int r,c;
char map[MAX][MAX];
bool visit[MAX][MAX];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
bool alpha[130];
int ans;
void dfs(int y,int x,int cnt)
{
	visit[y][x]=1;	
	alpha[map[y][x]]=1;
//	printf("%d %d\n",y,x);
	ans=max(ans,cnt);
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny>=r || nx>=c || nx<0 || ny<0)
			continue;
		
		if(!visit[ny][nx] && !alpha[map[ny][nx]])
		{
			visit[ny][nx]=1;
			alpha[map[ny][nx]]=1;
			dfs(ny,nx,cnt+1);
			visit[ny][nx]=0;
			alpha[map[ny][nx]]=0;		
		}
	}
	
}

int main(int argc, char** argv) {
	cin>>r>>c;
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>map[i][j];
	

	dfs(0,0,0);
	printf("%d",ans+1);
	return 0;
}

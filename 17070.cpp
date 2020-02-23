#include <iostream>
using namespace std;
const int MAX=16;
int map[MAX][MAX]={0};
int dy[]={0,1,1};
int dx[]={1,0,1};
int n;
int ans=0;

void go(int y,int x,int pipe)
{
	if(y==n-1 && x==n-1){
		ans++;
		return;
	}
	
	for(int i=0;i<3;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if( (i==0 && pipe==1 )||(i==1&&pipe==0))
			continue;
		
		if(ny>=n || nx>=n || map[ny][nx]==1)
			continue;
			
		if(i==2 &&( map[y][x+1]==1 || map[y+1][x]==1))
			continue;
			
		if(map[ny][nx]!=1){
			go(ny,nx,i);
		}	
		
	}
	
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	go(0,1,0);
	printf("%d",ans);
	return 0;
}

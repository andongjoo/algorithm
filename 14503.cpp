#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=51;
int map[MAX][MAX];
int n,m;
int r,c,dir;
int cnt=0;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

struct robott{
	int d;
	int y,x;
	
};


int main(int argc, char** argv) {
	cin>>n>>m;
	cin>>r>>c>>dir;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
		}
	}

	robott rob;
	rob.y=r;
	rob.x=c;
	rob.d=dir;
	while(1)
	{
//		
//		printf("\n%d %d dir:%d",rob.y,rob.x,rob.d);
		
		if(map[rob.y][rob.x]==0 )
		{
			map[rob.y][rob.x]=2;
			cnt++;
		}
		
		int check=0;
		for(int i=0;i<4;i++)
		{
			
			rob.d=rob.d-1;
			if(rob.d<0)
				rob.d=3;
				
			int ny=rob.y+dy[rob.d];
			int nx=rob.x+dx[rob.d];
			
			if(0<=ny && 0<=nx && ny<n && nx<m &&  map[ny][nx]==0)
			{
				rob.y=ny;
				rob.x=nx;
				check=1;
				break;
			}
		}
			if(check==1)
				continue;
				
			int temp_dir=rob.d-2;
			if(temp_dir==-2)
				temp_dir=2;
			if(temp_dir==-1)
				temp_dir=3;
			
			rob.x=rob.x+dx[temp_dir];
			rob.y=rob.y+dy[temp_dir];
			
			if(map[rob.y][rob.x]==1)
				break;
		
		
	
	}
	printf("%d",cnt);



	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
const int MAX=101;

int map[MAX][MAX];
int n,l,k;
int dir=0;

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
bool visit [MAX][MAX];
deque <pair<int,int> > dq;
queue <pair<int,char> > q;
int main(int argc, char** argv) {
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{	int r,c;
		cin>>r>>c;
		map[r][c]=1;
	}
	cin>>l;
	for(int i=0;i<l;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		q.push({x,c});
	}
	int t=0;
	dq.push_back({1,1});
	dir=0;
	visit[1][1]=true;
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(visit[i][j]==true)
//					printf("%1c",'x');
//				else
//					printf("%1c",'.');
//			}printf("\n");
//		}printf("\n");
	while(++t)
	{
	
	
		int nx,ny;
//		printf("t:%d y:%d x:%d dir:%d\n",t,dq.front().first,dq.front().second,dir);
		if(q.front().first==t-1)
		{
			if(dir==0)
			{
				if(q.front().second=='L')
				{
					dir=3;	
				}else{
					dir=2;
				}
			}else if (dir==1)
			{
				if(q.front().second=='L')
				{
					dir=2;	
				}else{
					dir=3;
				}
				
			}else if (dir==2)
			{
				if(q.front().second=='L')
				{
					dir=0;	
				}else{
					dir=1;
				}
			}else if (dir==3)
			{
				if(q.front().second=='L')
				{
					dir=1;	
				}else{
					dir=0;
				}
			}
			
			q.pop();
		}
		
		
		
		ny=dq.front().first+dy[dir];
		nx=dq.front().second+dx[dir];	
		
		if(nx>n || ny>n || nx<1 || ny<1)
		{
//			++t;
			break;
		}
		if(visit[ny][nx])
		{
//			++t;
			break;
		}
		if(map[ny][nx]==1)
		{
			map[ny][nx]=0;
			dq.push_front({ny,nx});
			visit[ny][nx]=true;
			l--;
		}else{
			dq.push_front({ny,nx});
			visit[dq.back().first][dq.back().second]=false;
			dq.pop_back();
			visit[ny][nx]=true;
		}
		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(visit[i][j]==true)
//					printf("%1c",'x');
//				else
//					printf("%1c",'.');
//			}printf("\n");
//		}printf("\n");
	
	}

	printf("%d",t);

	return 0;
}

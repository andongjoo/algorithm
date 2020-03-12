#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
const int MAX=101;
int ans,n,tc;
int map[MAX][MAX];
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,};

bool visit[MAX][MAX];
int oy,ox;
int ty,tx,block;

typedef struct{
	int size;
	int yy;
	int xx;
}data;
vector<data> v;
bool cmp(data a,data b)
{
	if(a.size==b.size)
	{
		return a.yy<b.yy;
	}
	
	return a.size<b.size;
}

void bfs(int y,int x)
{
	queue<pair<int,int> > q;
	
	q.push({y,x});
	visit[y][x]=true;
	while(!q.empty())
	{
		int cy=q.front().first;
		int cx=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int ny = cy+dy[i];
			int nx = cx+dx[i];
			
			if(nx>=n || ny>=n || nx<0 || ny<0)
				continue;
				
			if(!visit[ny][nx] && map[ny][nx]!=0)
			{
				q.push({ny,nx});
				visit[ny][nx]=true;
			}
		}
	}
}


int main(int argc, char** argv) {
	cin.tie(0);
	
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		ans=0;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>map[i][j];
				visit[i][j]=false;
				
			}
		}
		block=0;
		v.clear();
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visit[i][j] &&map[i][j]!=0)		
				{
					
					block++;
					int row=1,col=1;
					int k=j+1;
					while(true)
					{
						if(map[i][k]==0 || k>=100)
							break;
						
						if(map[i][k]!=0)
						{
							
							k++;
							col++;
						}
					}
					
					k=i+1;
					while(true)
					{
						if(map[k][j]==0 || k>=100)
							break;
						
						if(map[k][j]!=0)
						{
							
							k++;
							row++;
						}
					}
					bfs(i,j);
					
					v.push_back({col*row,row,col});					


				}	
			}
		}
		
		sort(v.begin(),v.end(),cmp);
		printf("#%d %d ",t,v.size());
		
		for(int i=0;i<v.size();i++)
		{
			printf("%d %d ",v[i].yy,v[i].xx);
		}printf("\n");
	
	}

	return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX=10;
int a[MAX][MAX];
int visit[MAX][MAX][MAX];
int ans;
int n;
int tc;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

typedef struct {
	int y;
	int x;
	int l;
	int idx;
}data;

vector<int> f[MAX][MAX];

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		cin>>n;
		queue<data> q;
		int index=0;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				for(int k=0;k<10;k++)
				{
					visit[i][j][k]=0;
				}
			}
		}
		
		for(int i=0;i<n;i++)	
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]==1)
				{
					data d={i,j,0,index++};
					q.push(d);
				}else if (a[i][j]>1 && a[i][j]<=10)
				{
					f[i][j].push_back(a[i][j]);	
				}
				
			}
		}
		
		int time=0;
		while(!q.empty())
		{
			if(index<=1)
				break;
			time++;
			int r=q.front().y;
			int c=q.front().x;
			int l=q.front().l;
			int idx=q.front().idx;
				
			for(int i=0;i<4;i++)
			{
				int ny=r+dy[i];
				int nx=c+dx[i];
				if(ny>=n || nx>=n || nx<0 || ny<0)
					continue;
				
				if(!visit[ny][nx][idx])
				{
					
					if(a[ny][nx]>1 && a[ny][nx]<=10)
					{
						if(f[ny][nx].size()<3)
						{
							visit[ny][nx][l]=1;
							f[ny][nx].push_back(0);
						
						}else if (f[ny][nx].size()==3)
						{
							q.push({r,c,l+1,idx});
						}
					}else{
					
						visit[ny][nx][idx]=1;
						data d={ny,nx,l+1,idx};
						q.push(d);		
					}
				}
				
			}
			
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(f[i][j].size()>=1)
					{
						for(int k=0;k<f[i][j].size();k++)
						{
							f[i][j][k]++;
						}
						
						if(f[i][j][0]>a[i][j])
						{
							f[i][j][0]=f[i][j][f[i][j].size()-1];
							f[i][j].pop_back();
							index--;
						}
						
					}
				}
			}
			
		}
		
		
		
		
		
		ans=time;
		
		printf("#%d %d\n",t,ans);
	}
	
	
	
	
	return 0;
}

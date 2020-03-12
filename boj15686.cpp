#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int ans=987987987;
const int MAX=51;
int n,m;
int map[MAX][MAX];
vector<pair<int,int> > chicken;
vector<pair<int,int> > selected_chicken;
vector<pair<int,int> > home;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int cnt[MAX][MAX];
int cpymap[MAX][MAX];
int check[MAX][MAX];


int solve()
{
	int len=0;
	for(int i=0;i<(int)home.size();i++)
	{
	
		queue<pair<int,int> > q;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				cnt[j][k]=0;
				check[j][k]=0;
			}
		}
		
		while(!q.empty())
			q.pop();
		
//		printf("%d %d start\n",home[i].first,home[i].second);	
		q.push({home[i].first,home[i].second});
		check[home[i].first][home[i].second]=1;
		
		while(!q.empty())		
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			if(cpymap[x][y]==2)
			{
				len+=cnt[x][y];
//				printf("len:%d\n",cnt[x][y]);
				break;
			}
			for(int j=0;j<4;j++)
			{
				int nx=dx[j]+x;
				int ny=dy[j]+y;
				
				if (ny>=n || nx>= n || nx<0 || ny<0)
					continue;
				
				if(!check[nx][ny])
				{
					q.push({nx,ny});
					cnt[nx][ny]=cnt[x][y]+1;
					check[nx][ny]=1;
				}
				
			}
			
		}
		
		
		
		
	}
	
	return len;
}

int t;
void go(int index,int cnt)
{
	if(index>(int)chicken.size())
		return;
		
	if(cnt==m)
	{
		int len=0;
		
		for(int i=0;i<(int)home.size();i++)
		{
			int d=987987987;
			for(int j=0;j<(int)selected_chicken.size();j++)
			{
				d=min(d,abs(home[i].first-selected_chicken[j].first)+abs(home[i].second-selected_chicken[j].second));
			}
			len+=d;	
		}
		
		ans=min(ans,len);
	}
	
	selected_chicken.push_back(chicken[index]);
	go(index+1,cnt+1);
	selected_chicken.pop_back();
	go(index+1,cnt);
	
}


int main(int argc, char** argv) {
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==2)
			{
				chicken.push_back({i,j});
			}
			
			if(map[i][j]==1)
			{
				home.push_back({i,j});
			}
		}
	}
	go(0,0);
	printf("%d\n",ans);
	
	return 0;
}

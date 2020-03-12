#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX=100+1;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int a[MAX][MAX];
int dist[MAX][MAX];
int n,m;
int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	
	queue<pair<int,int> > q;
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			a[i][j]=s[j]-'0';
			dist[i][j]=987987987;
		}
	}
	

	
	
	q.push(make_pair(0,0));
	dist[0][0]=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(ny>=n || ny<0 ||nx>=m || nx<0)
				continue;
			
		
			
			
		 if(a[nx][ny]==0)
			{
			
				if(dist[nx][ny]>dist[x][y])
				{
					q.push(make_pair(nx,ny));
					dist[nx][ny]=dist[x][y];
				}
			}
		else if(a[nx][ny]==1)
			{
				if(dist[nx][ny]>dist[x][y]+1)
				{
				
					q.push(make_pair(nx,ny));
					dist[nx][ny]=dist[x][y]+1;	
				}
				
			}
			
		}
		
	}
//	for(int i=0;i<m;i++)
//	{
//		for(int j=0;j<n;j++)
//			printf("%d ",dist[i][j]);
//		printf("\n");
//	}
	
	printf("%d",dist[m-1][n-1]);
	
	return 0;
}

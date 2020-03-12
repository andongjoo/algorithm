#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
const int MAX=16;

vector<pair<int,int> > pos;
int map[MAX][MAX];
int n,m,d;
int ans;
int arc[3];
int line;
int dist(int r1,int c1,int r2,int c2)
{
	return abs(r1-r2)+abs(c1-c2);
}


void solve()
{
	
	int cnt=0;
	int sum=0;
	int tmpMap[MAX][MAX];
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<m;j++)
			{
				tmpMap[i][j]=map[i][j];
			}
	}
//	printf("%d\n",line);
	while(cnt<line)
	{
		printf("%d",cnt);
		pos.clear();
		for(int i=0;i<3;i++)
		{
			int shotX=999;
			int shotY=999;
			int tmpDist=d;
			
			for(int j=n-1;j>=0;j--)
			{
				for(int k=0;k<m;k++)
				{
					if(tmpMap[j][k]==1 && dist(j,k,n,arc[i])<tmpDist)
					{
						tmpDist=dist(j,k,n,arc[i]);
						shotX=j;
						shotY=k;
					}
					else if (tmpMap[j][k]==1 && dist(j,k,n,arc[i])==tmpDist)
					{
						if(k<shotY)
						{
							shotX=j;
							shotY=k;
						}
					} 
				}
			}
			if(shotX!=999 && shotY!=999)
			{
				pos.push_back({shotX,shotY});
			}
		}
		for(int i=0;i<pos.size();i++)
		{
			if(tmpMap[pos[i].first][pos[i].second]==1)
			{
				tmpMap[pos[i].first][pos[i].second]=0;
				sum++;
			}
		}
		
		
		for(int i=n-1;i>=1;i--)
		{
			for(int j=0;j<m;j++)
			{
				tmpMap[i][j]=tmpMap[i-1][j];
			}
		}
		for(int i=0;i<m;i++)
		{
			tmpMap[0][i]=0;
		}
		
		cnt++;
//		printf("hi\n");
	}	
	
	ans=max(ans,sum);
}

void archer(int index,int cnt)
{
	
	if(cnt==3)
	{
		solve();
		return;
	}
	
	for(int i=index;i<m;i++)
	{
		arc[cnt]=i;
		archer(index+1,cnt+1);
	}
	
}


int main(int argc, char** argv) {
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(false);
	line=-1;
	cin>>n>>m>>d;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==1 && line==-1)
			{
				line=n-i;
//				printf("line: %d\n",line);
			}
			
		
		}
	}
	archer(0,0);
	
	
	printf("%d",ans);
	
	
	
	
	return 0;
}

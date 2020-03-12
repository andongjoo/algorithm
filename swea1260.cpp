#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX=101;
int map[MAX][MAX];



vector<pair<int,int> > v;
vector<int> m;
int tc,n,k;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int dp[MAX][MAX];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}

void dfs(int r,int c)
{
	map[r][c]=0;

	for(int i=0;i<4;i++)
	{
		int ny=r+dy[i];
		int nx=c+dx[i];
		
		if(ny>= n || nx>=n || ny<0 || nx<0)
			continue;
			
		if(map[ny][nx]!=0)
			dfs(ny,nx);
		
	}
	
}

int main(int argc, char** argv) {

	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		m.clear();
		v.clear();
		cin>>n;
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<MAX;j++)
			{
				dp[i][j]=0;
			}
		}
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>map[i][j];
				
				
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map[i][j]!=0)
				{
					
					k=i+1;
					int row=1,col=1;
					
					while(k<n)
					{
						if(map[k][j]!=0)	
						{
							row++;
							k++;
						}else{
							break;
						}
						
					}
					
					k=j+1;
					
					while(k<n)
					{
						if(map[i][k]!=0)
						{
							col++;
							k++;
						}else{
							break;
						}
					}
					
					v.push_back(make_pair(row,col));
					dfs(i,j);
				}
				
			}
		}
		
		int ans=0;
		
		sort(v.begin(),v.end(),cmp);
		m.push_back(v[0].first);
		for(int i=0;i<v.size();i++)
		{
//			m.push_back(v[i].row);
			m.push_back(v[i].second);
		}
		int size = m.size();

//	for(int i=0;i<m.size();i++)
//		printf("%d ",m[i]);
//	printf("\n");


	for(int k=1;k<size;k++)
	{
		for(int i=1;i<size-k;i++)
		{
			int j=i+k;
			dp[i][j]=987987987;
			for(int l=i;l<j;l++)
			{
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l+1][j]+m[i-1]*m[l]*m[j]);
			}
			
			
		}
		
	}



//    cout << dp[1][size] << endl;
//    for (int i = 1; i <= v.size(); i++)
//    {
//        for (int j = 1; j <= v.size(); j++)
//        {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
		ans=dp[1][v.size()];		
		printf("#%d %d\n",t,ans);
	}

	return 0;
}

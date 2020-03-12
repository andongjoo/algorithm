#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int tc,ans;
int n,m,c;
int a[10][10];
int visit[10][10];


int max_num[2];
vector<int> v1,v2;
bool select[10];

void solov(vector<int> v,int idx,int iidx,int total,int cost)
{
	
	if(total>c)
		return;
		
	if(max_num[idx]<cost)
	{
		max_num[idx]=cost;
	}
	
	for(int i=iidx;i<m;i++)
	{
		if(select[i])
			continue;
		select[i]=true;
		solve(v,idx,i,total+v[i],cost+(v[i]*v[i]));
		select[i]=false;
	}
	
}

void dfs(int y,int x,int order)
{
	if(order==2)
	{
		max_num[0]=0;
		max_num[1]=0;
		v1.clear();
		v2.clear();
		for(int i=0;i<10;i++)
			select[i]=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(visit[i][j]==1)
				{
					v1.push_back(a[i][j]);
				}else if (visit[i][j]==2)
				{
					v2.push_back(a[i][j]);	
				}
				
			}
		}
		
			
		
		
		return;
	}
		
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(check(i,j))
			{
				make_visit(i,j,2);
				dfs(i,j,2);
				make_visit(i,j,2);
			}
		}
	}
	
}

void make_visit(int y,int x,int dc)
{
	for(int i=x;i<x+m;i++)
	{
		visit[y][i]=dc;
	}
}

bool check(int y,int x)
{
	for(int i=x;i<x+m;i++)
	{
		if(visit[y][x] || i>=n) 
			return false;
	}
	return true;
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
//	ios::sync_with_stdio(false);
	
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		cin>>n>>m>>c;
		
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				visit[i][j]=false;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		
		for(int k=0;k<2;k++)
		{
			
						
			vector<int> tmp;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(check(i,j))
					{
						
						make_visit(i,j,1);
						dfs(i,j,1);
						make_visit(i,j,0);
					}
				}
			}
					
					
		}

		printf("#%d %d\n",t,ans);
	}

	
	
	return 0;
}

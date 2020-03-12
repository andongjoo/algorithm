#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int t,n,m;
vector<int> v[20001];
int group[20001];
int flag;

void dfs(int node,int g)
{
	group[node]=g;
	
	for(int i=0;i<v[node].size();i++)
	{
		int next=v[node][i];
		if(!group[next])
		{
			dfs(next,3-g);
		}
	}
}

void check(void)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int next=v[i][j];
			if(group[i]==group[next])
				flag=0;
		}
	}
}


int main(int argc, char** argv) {

	cin>>t;
	for(int i=0;i<t;i++)
	{
		flag=1;
		
		for(int j=0;j<20001;j++)
		{
			v[j].clear();
		}
		for(int j=0;j<20001;j++)
		{
            group[j]=0;
		}
			
		cin>>n>>m;
		for(int j=0;j<m;j++)
		{
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
//		for(int j=1;j<=n;j++)
//		sort(v[j].begin(),v[j].end());
		
		for(int j=1;j<=n;j++)
		{
			if(group[j]==0)
			{
				dfs(j,1);
			
			}
		}
		check();
		 if(flag)
		 	printf("YES\n");
		else
			printf("NO\n");
		
	}
	
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> v[2001];
int visit[2001];
bool flag=false;

int dfs(int node,int cnt)
{
	
	visit[node]=true;
	
	for(int i=0;i<v[node].size();i++)	
	{
		int next=v[node][i];
		if(!visit[next])
		{	
			if(cnt+1==4)
				return 1;
			if(dfs(next,cnt+1)==1)
				return 1;
//			visit[next]=false;
		}
	}
	visit[node]=false;
	return 0;
}

int main(int argc, char** argv) {
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2001;j++)
		{
			visit[j]=false;
		}
//		visit[i]=true;
		if(dfs(i,0))
		{
			printf("1");
			return 0;
		}
	}
	printf("0");
	return 0;
}

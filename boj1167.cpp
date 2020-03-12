#include <iostream>
#include <vector>
using namespace std;

bool visit[100001];
vector<int> g[100001];
vector<int> v[100001];
int dp[100001];

int ans;
int fnode;

void dfs(int node,int len)
{
	if(visit[node])
		return;
		
	visit[node]=1;
	
	if(ans<len)
	{
		ans=len;
		fnode=node;
	}
	for(int i=0;i<g[node].size();i++)
	{
		int next=g[node][i];
		int l=v[node][i];
		dfs(next,len+l);
		
	}
	
	
}


int main(int argc, char** argv) {
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int node;
		cin>>node;
		while(1)
		{
			int next;
			cin>>next;
			if(next==-1)
			{
				break;
			}
			int len;
			cin>>len;
			g[node].push_back(next);
			v[node].push_back(len);
		}
	}
	
	dfs(1,0);
	for(int i=1;i<=100000;i++)
	{
		visit[i]=false;
	}
	ans=0;
	dfs(fnode,0);
	printf("%d",ans);
	return 0;
}

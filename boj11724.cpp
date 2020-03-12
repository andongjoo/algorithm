#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10001];
bool visit[10001];
int n,m;

void dfs(int node)
{
	visit[node]=true;
	
	for(int i=0;i<v[node].size();i++)
	{
		int next=v[node][i];
		if(!visit[next])
		{
			dfs(next);
		}
		
	}
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

	for(int i=0;i<v[i].size();i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			dfs(i);
			cnt++;
		}
	}

	printf("%d",cnt);
	return 0;
}

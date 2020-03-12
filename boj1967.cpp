#include <iostream>
#include <vector>
using namespace std;
const int MAX=10000 + 1;
int n;
vector<int> g[MAX];
vector<int> v[MAX];
bool visit[MAX];
int fnode;
int l;

void dfs(int node,int len)
{
	if(len>l)
	{
		l=len;
		fnode=node;
	}
	
	visit[node]=true;
	
	
	for(int i=0;i<g[node].size();i++)
	{
		int next=g[node][i];
		int value=v[node][i];
		if(!visit[next])
		{
			dfs(next,len+value);
		}
		
	}
	
	
}


int main(int argc, char** argv) {
	cin>>n;
	
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		
		g[a].push_back(b);
		g[b].push_back(a);	
		
		v[a].push_back(c);
		v[b].push_back(c);	
		
	}	
	
	dfs(1,0);
	for(int i=0;i<MAX;i++)
	{
		visit[i]=0;
	}
	l=0;
	dfs(fnode,0);
	printf("%d",l);
	return 0;
}

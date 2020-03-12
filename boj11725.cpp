#include <iostream>
#include <vector>
using namespace std;

bool visit[100001];
int p[100001];
vector<int> g[100001];	
void parent(int node)
{
	visit[node]=1;
	
	for(int i=0;i<g[node].size();i++)
	{
		int next=g[node][i];
		if(!visit[next])	
		{
			p[next]=node;
			parent(next);
		}
	}	
	
}

int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	parent(1);
	
	for(int i=2;i<=n;i++)
	{
		printf("%d\n",p[i]);
	}
	
	return 0;
}

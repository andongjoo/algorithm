#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,s;

	vector<int> v[1001];
bool check[1001];
bool check2[1001];
void dfs(int node)
{
	check[node]=true;
	printf("%d ",node);
	
	for(int i=0;i<v[node].size();i++)
	{
		if(false==check[v[node][i]])
		{
			dfs(v[node][i]);
		}
	}
}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	
	while(!q.empty())
	{
		
		int front=q.front();
		check2[front]=true;
		printf("%d ",front);
		q.pop();
		for(int i=0;i<v[front].size();i++)
		{
			int next=v[front][i];
			if(!check2[next])
			{
				check2[next]=true;
				q.push(next);
			}
		}
		
	}
}

int main(int argc, char** argv) {
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);		
	}
	
	for(int i=0;i<1001;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	
	dfs(s);
	printf("\n");
	bfs(s);
	

	return 0;
}

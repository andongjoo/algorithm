#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[1001];
bool visit[1001];
int n,t;

void dfs(int node)
{
	visit[node]=true;
//	printf("%d ",node);
	int next=v[node][0];
		
	if(!visit[next])
		dfs(next);
	
}

int main(int argc, char** argv) {
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<1001;j++)
		{
			v[j].clear();
			visit[j]=0;
		}
		int cnt=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int node;
			cin>>node;
			v[j].push_back(node);
			
		}
		for(int j=1;j<=n;j++)
		{
			if(!visit[j])
			{
				cnt++;
				dfs(j);
			}
		}
//		printf("\n");
		printf("%d\n",cnt);
		
	}
	
	
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int cnt;
int v[100001];
bool visit[100001];
bool check[100001];


void dfs(int node)
{
	visit[node]=true;

	int next=v[node];
	
	if(!visit[next])
		dfs(next);
	else if (!check[next])
	{
			for(int i=next; i!=node;i=v[i])
				cnt++;
			cnt++;
	}
	
	check[node]=true;
	
}



int t,n;
int main(int argc, char** argv) {
	cin>>t;
	for(int k=0;k<t;k++)
	{
		for(int i=0;i<100001;i++)
		{
			v[i]=0;
			visit[i]=0;
			check[i]=0;
		}
		cnt=0;
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
		}
		
		for(int i=1;i<=n;i++)
		{
		
			if(!visit[i])
				dfs(i);
		}
		
		printf("%d\n",n-cnt);
	}
	

	return 0;
}

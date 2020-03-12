#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[10+1][10+1];
int b[11][11];
int ans=1e9;

void dfs(vector<int> &path,vector<bool> visit,int sum,int x)
{

	if(path.size()>=n)
	{
//		printf("%d\n",sum);
		int here=path.back();
		if(a[here][x]!=0)
			ans=min(ans,sum+a[here][x]);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
			int here=path.back();
			if(a[here][i]==0)
				continue;
			path.push_back(i);
			visit[i]=true;
			dfs(path,visit,sum+a[here][i],x);
			visit[i]=false;
			path.pop_back();
			
		}
	}
}

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		vector<int> path(1,i);
		vector<bool> visit(n,0);
		visit[i]=true;
		dfs(path,visit,0,i);
	
	}
	printf("%d",ans);
		
	
	return 0;
}

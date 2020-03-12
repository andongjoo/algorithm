#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;

int t,n,node1,node2;
int parent[MAX];
//vector<int> child[MAX];

void init()
{
	for(int i=0;i<MAX;i++)
	{
//		child[i].clear();
		parent[i]=-1;
	}

}

int depth(int node)
{
	int ret=0;
	while(parent[node]!=-1)
	{
	
		ret++;
		node=parent[node];
	
	}
	return ret;
}

int find(int n1,int n2,int n1d,int n2d)
{
	if(n1d>n2d)
	{
		while(n1d!=n2d)
		{
			n1=parent[n1];
			n1d--;
		}
		
	}
	
	if(n2d>n1d)
	{
		while(n1d!=n2d)
		{
			n2=parent[n2];
			n2d--;
		}
	}
	
	if(n1d==n2d)
	{
		while(n1!=n2)
		{
			n2=parent[n2];
			n1=parent[n1];
		}
		
	}
	
	return n1;
}

int main(int argc, char** argv) {
	
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	
	while(t--)
	{
		init();
		cin>>n;
		
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			parent[b]=a;
		}
		cin>>node1>>node2;
		
		int n1_d=depth(node1);
		int n2_d=depth(node2);
		
		int ans=find(node1,node2,n1_d,n2_d);
		printf("%d\n",ans);
	}
	
	return 0;
}

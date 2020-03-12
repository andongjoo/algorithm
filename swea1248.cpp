#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v,e,a,b,tc,ans;
int l;


int get_depth(vector<int> &p,int node)
{
	int d=0;
	
	while(node!=1)
	{
		d++;
		node=p[node];
	}
	return d;
}

int sol(vector<int> &p,int a1,int b1,int ad,int bd)
{
	if(ad>bd)
	{
		while(ad!=bd)
		{
			ad--;
			a1=p[a1];
		}
	}
	if(ad<bd)
	{
		while(ad!=bd)
		{
			bd--;
			b1=p[b1];
		}
	}
	
	if(ad==bd)
	{
		while(a1!=b1)
		{
			a1=p[a1];
			b1=p[b1];
		}
	}
	
	return a1;
}

int get_len(vector<vector<int>> &c,int cur)
{
	int ret=1;
	if(c[cur].size()==0)
		return 1;
		
	for(int i=0;i<c[cur].size();i++)
	{
		ret+=get_len(c,c[cur][i]);
	}
	return ret;
}

int main(int argc, char** argv) {
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		
		cin>>v>>e>>a>>b;
		
		vector<vector<int>> child(v+1);
		vector<int> parent(v+1);
		for(int i=0;i<e;i++)
		{
			int a1,a2;
			cin>>a1>>a2;
			parent[a2]=a1;
			child[a1].push_back(a2);
		}
		
		
		int d1=get_depth(parent,a);
		int d2=get_depth(parent,b);
		ans=sol(parent,a,b,d1,d2);
		l=get_len(child,ans);
		
	
		
		
		
        cout << "#" << t << ' ' << ans << ' ' << l << '\n';
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>
using namespace std;

const int MOD=10000;

int t,a,b;
bool visit[10001];

int d(int n)
{
	return (2*n)%MOD;	
}

int s(int n)
{
	if(n==0)
		return 9999;
	else
		return n-1;
}

int l(int n)
{
	return (n%1000)*10+n/1000;
}

int r(int n)
{
	return (n%10)*1000+(n/10);
}
queue<pair<int,string> > q;
void bfs(int n)
{
	string str="";
	q.push(make_pair(n,str));
	
	while(!q.empty())
	{
		int cur=q.front().first;
		string temp=q.front().second;
		q.pop();
		
		if(cur==b)
		{
			cout<<temp<<"\n";
			break;
		}
		
		if( !visit[d(cur)])
		{
			visit[d(cur)]=1;
			
			q.push(make_pair(d(cur),temp+'D'));
			
		}
		
		if(!visit[s(cur)])
		{
			
			visit[s(cur)]=1;
			q.push(make_pair(s(cur),temp+'S'));
	
		}
		
		if(!visit[l(cur)])
		{
			
			visit[l(cur)]=1;
			
			q.push(make_pair(l(cur),temp+'L'));
		}
		
		if(!visit[r(cur)])
		{
			
			visit[r(cur)]=1;
			q.push(make_pair(r(cur),temp+'R'));
			
		}
		
		
	}
	
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	for(int k=0;k<t;k++)
	{
		cin>>a>>b;
		for(int i=0;i<=10000;i++)
		{
			visit[i]=0;
		}
		while(!q.empty())
			q.pop();
		bfs(a);	
	
	
	
	
	}
	
	
	
	return 0;
}

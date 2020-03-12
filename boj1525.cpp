#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
queue<int> q;
map<int,int> m;
map<int,int> check;
int ans=1e9;

void bfs()
{
	while(!q.empty())
	{
		
		int cur=q.front();
		q.pop();
	
		
		string s=to_string(cur);
		int index=s.find('9');
		int x=index%3;
		int y=index/3;
		
		
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || ny<0 || ny>=3 || nx>=3)
				continue;
			string temp=s;
			
			swap(temp[y*3+x],temp[ny*3+nx]);
			int next=stoi(temp);
			if(!check.count(next))
			{
				check[next]=check[cur]+1;
				q.push(next);
			}
		
		}
		
	
	}
	
}

int main(int argc, char** argv) {
	int n=0,nn=0;
	for(int i=0;i<9;i++)
	{
		cin>>n;
		if(n==0)
			n=9;
		nn= nn*10+n;
	}
	
	q.push(nn);
	bfs();
	
	if(!check.count(123456789))
		printf("-1");
	else
		printf("%d",check[123456789]);	
	return 0;
}

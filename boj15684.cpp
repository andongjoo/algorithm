#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX=30;
int m,n,h;
int map[MAX][MAX];
int ans=4;

bool ladder(){

	for(int i=0;i<n;i++)
	{
		int k=i;
		for(int j=0;j<h;j++)
		{
			if(map[j][k])
				k+=1;
			else if (k>0 &&map[j][k-1])
				k-=1;
		}
		if(k!=i)
			return false;
	}


	return true;
}

void solve(int cnt,int x,int y)
{
	if(ans<=cnt)
		return;
	if(ladder())
	{
		ans=min(cnt,ans);
		return;
	}
	
	if(cnt==3)
	{
		return;
	}
	
	for(int i=x;i<h;i++,y=0)
	{
		for(int j=y;j<n-1;j++)
		{
			if(map[i][j])
			{
				j+=1;
			}else {
				map[i][j]=1;
				solve(cnt+1,i,j+2);
				map[i][j]=0;
			}
		}
	}
	

}

int main(int argc, char** argv) {
	
	cin>>n>>m>>h;
	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		map[x-1][y-1]=1;
	}
	solve(0,0,0);
	
	if(ans<4)
		cout<<ans;
	else
		cout<<-1;
	return 0;
}

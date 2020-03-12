#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int t;
int a[4][4];
int check[10000000];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
void dfs(int y,int x,int cnt,int num)
{
	if(cnt==7)
	{
		check[num]=1;	
		return;
	}
	
	
	for(int i=0;i<4;i++)
	{
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		if(ny>=4 || nx>=4 || nx<0 ||ny<0)
			continue;
			
		num*=10;	
		dfs(ny,nx,cnt+1,num+a[y][x]);
		num/=10;
	
	}
	
}

int main(int argc, char** argv) {
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int ans=0;
	
		
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<10000000;i++)
		{
			check[i]=0;
		}
		
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				
				dfs(i,j,0,0);		
			}
		}
		
		
		for(int i=0;i<10000000;i++)
		{
			if(check[i]==1)
				ans++;
		}
		
		printf("#%d %d\n",k,ans);
	}
	
	
	return 0;
}

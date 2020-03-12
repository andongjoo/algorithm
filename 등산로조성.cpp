#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

bool check[9][9];
int a[9][9];
int n,k;
int result;

void go(int r,int c,int cnt,bool flag)
{
	
	check[r][c]=1;
	for(int i=0;i<4;i++)
	{
		
		int ny=r+dy[i];
		int nx=c+dx[i];
		
		if(ny<0 || ny>n-1 || nx >n-1 || nx<0 )
			continue;
			
		if(check[ny][nx])
			continue;
			
		if(a[ny][nx]<a[r][c])
		{
			go(ny,nx,cnt+1,flag);
			check[ny][nx]=0;
		}
		else if (a[ny][nx]>=a[r][c] && !flag)
		{
			for(int j=1;j<=k;j++)
			{
				
				flag=1;
				a[ny][nx]-=j;
				if(a[ny][nx]<a[r][c] ){
					go(ny,nx,cnt+1,flag);
					check[ny][nx]=0;
				}
				a[ny][nx]+=j;
				flag=0;
			}
		}
		
		if(result<cnt)	
			result=cnt;
	}
	
}

int main(int argc, char** argv) {

	int test;
	cin>>test;
	for(int t=1;t<=test;t++)
	{
	
		result=0;
		
		n=0;k=0;
		cin>>n>>k;
		int high=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				high=max(high,a[i][j]);
			}
		}
		
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==high)
				{
					
					for(int z=0;z<9;z++)
					{
						for(int x=0;x<9;x++)
						{
							check[z][x]=0;
						}
					}
					
					go(i,j,1,0);
				}
			}
		}
		
		
		
		printf("#%d %d\n",t,result);	
	}
	
	
	return 0;
}

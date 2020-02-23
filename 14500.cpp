#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=501;
int paper[MAX][MAX]={0};
int ans=0;

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

int n,m;

void fun1(int y,int x)
{
	int cnt=0;
			
	if(0<=x && 0<=y && y<n-3 && x<m)
	{
		cnt+=paper[y][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y+2][x];
		cnt+=paper[y+3][x];
	}
	ans=max(ans,cnt);
	
	cnt=0;
	
	if(0<=x && 0<=y && y<n && x<m-3)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y][x+2];
		cnt+=paper[y][x+3];
	}
	ans=max(cnt,ans);
}

void fun2(int y,int x)
{
	int cnt=0;
	
	if( 0<=y && 0<=x && y<n-1 && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y+1][x+1];
	}
	
	ans=max(ans,cnt);
	
	
}

void fun3(int y,int x)
{
	int cnt=0;
	
	if(0<y && 0<=x && y<n-1 && x<m-1)
	{
		cnt+=paper[y-1][x];
		cnt+=paper[y][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y+1][x+1];
	}
	
	ans=max(ans,cnt);
	
	cnt=0;
	if(0<=y && 0<x && y<n-1 && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y+1][x];
		cnt+=paper[y+1][x-1];
	}
	
	ans=max(ans,cnt);
	
	cnt=0;
	if(0<y && 0<=x && y<n-1 && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y-1][x+1];
	}
	ans=max(ans,cnt);

	
	cnt=0;
	if(0<x && 0<=y && x<m-1 && y<n-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y+1][x+1];
		cnt+=paper[y][x-1];
	}
	ans=max(ans,cnt);

}

void fun4(int y,int x)
{
	int cnt=0;
	
	if(0<=x && 1<y && x<m-1 && y<n)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y-1][x];
		cnt+=paper[y-2][x];
	}
	ans=max(ans,cnt);
	
	
	
	cnt=0;
	if(0<x && 0<=y && x<m && y<n-2)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x-1];
		cnt+=paper[y+1][x];
		cnt+=paper[y+2][x];
	}
	
	ans=max(ans,cnt);
	
	
	
	cnt=0;
	if(0<=y && 0<=x && y<n-1 && x<m-2)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y][x+2];
		cnt+=paper[y+1][x];
	}
	
	ans=max(ans,cnt);
	
	
	
	cnt=0;
	if(1<x && 0<y && y<n && x<m)
	{
		cnt+=paper[y][x];
		cnt+=paper[y-1][x];
		cnt+=paper[y][x-1];
		cnt+=paper[y][x-2];
	}
	
	ans=max(ans,cnt);
	
	
	cnt=0;
	if(0<=x && 0<=y && y<n-2 && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y+1][x];
		cnt+=paper[y+2][x];
	}
	ans=max(ans,cnt);
	
	cnt=0;
	if(0<x && 1<y && x<m && y<n)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x-1];
		cnt+=paper[y-1][x];
		cnt+=paper[y-2][x];
	}
	ans=max(ans,cnt);
	
	cnt=0;
	if(0<y && 0<=x && x<m-2 && y<n)
	{
		cnt+=paper[y][x];
		cnt+=paper[y-1][x];
		cnt+=paper[y][x+1];
		cnt+=paper[y][x+2];
	}
	ans=max(ans,cnt);
	
	cnt=0;
	if(1<x && 0<=y && y<n-1 && x<m)
	{
		cnt+=paper[y][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y][x-1];
		cnt+=paper[y][x-2];
	}
	ans=max(ans,cnt);
}

void fun5(int y,int x)
{
	int cnt=0;
	if(0<=y && 0<x && y<n-1 && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y][x-1];
		cnt+=paper[y+1][x];
		cnt+=paper[y][x+1];
	}
	
	ans=max(ans,cnt);
	
	cnt=0;
	if(0<y && 0<x && y<n && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y-1][x];
		cnt+=paper[y][x-1];
		cnt+=paper[y][x+1];
	}
	ans=max(ans,cnt);
	
	
	cnt=0;
	if(0<=x && 0<y && y<n-1 && x<m-1)
	{
		cnt+=paper[y][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y-1][x];
		cnt+=paper[y][x+1];
	}
	ans=max(ans,cnt);
	
	
	
	cnt=0;
	if(0<x && 0<y && y<n-1 && x<m)
	{
		cnt+=paper[y][x];
		cnt+=paper[y-1][x];
		cnt+=paper[y+1][x];
		cnt+=paper[y][x-1];
	}
	ans=max(ans,cnt);
}


int main(int argc, char** argv) {

	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>paper[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			fun1(i,j);
			fun2(i,j);
			fun3(i,j);
			fun4(i,j);
			fun5(i,j);
		}
	}
	
	printf("%d",ans);


	return 0;
}

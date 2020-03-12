#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
const int MAX=12;

typedef struct{
	int x;
	int y;
}pos;
bool check[12];
pos a[12];
int n,result;
int startx,starty,endx,endy;
int len(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}

void dfs(int index,int x,int y,int total)
{
	
	if(index==n)
	{
		total+=len(endx,endy,x,y);
		result=min(result,total);
		total-=len(endx,endy,x,y);
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!check[i])
		{
			check[i]=true;
			dfs(index+1,a[i].x,a[i].y,total+len(a[i].x,a[i].y,x,y));
			check[i]=false;
		}
	}
	
}

int main(int argc, char** argv) {
	
	int test;
	cin>>test;
	for(int t=1;t<=test;t++)
	{
		result=987987987;
		cin>>n;
		cin>>startx>>starty>>endx>>endy;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].x>>a[i].y;
			check[i]=false;	
		}
	
		dfs(0,startx,starty,0);
		
	
		printf("#%d %d\n",t,result);
	
	}

	return 0;
}

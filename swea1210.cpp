#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int a[100][100];

bool search(int r,int c)
{
	
	int y=r;
	int x=c;
	
	while(x<=99 && y<=99)
	{
		if (a[y][x]==2)
			return true;
	
	
		if(x+1<100 &&a[y][x+1]==1)		
		{	
			while(1)
			{
				x++;	
				if(a[y+1][x]==1)	
				{
					y=y+1;
					break;
				}
			}	
			
			
		}else if (x-1>=0 && a[y][x-1]==1)
		{
			while(1)
			{
				x--;
				if(a[y+1][x]==1)
				{
					y=y+1;
					break;
				}
			}
		}else
		{
			y++;
		}
			
	
	}
	

	return false;
}


int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	
	for(int t=1;t<=10;t++)
	{
		int tn;
		cin>>tn;
		int ans=0;
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				cin>>a[i][j];
	
		for(int i=0;i<100;i++)
		{
			if(a[0][i]==1)
			{
				if(search(0,i))
					ans=i;
			}
		}
	
		
		printf("#%d %d\n",tn,ans);
	}

	return 0;
}

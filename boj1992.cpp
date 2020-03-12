#include <iostream>
using namespace std;
const int MAX=64+1;
char a[MAX][MAX];

void quadtree(int y,int x,int size)
{
	if(size==1)
	{
		printf("%d",a[y][x]);
		return;
	}
	
	int temp=a[y][x];
	for(int i=y;i<y+size;i++)
	{
		for(int j=x;j<x+size;j++)
		{
			if(a[i][j]!=temp)
			{
				printf("(");
				for(int k=0;k<2;k++)
				{
					for(int z=0;z<2;z++)
					{
						quadtree(y+(size/2)*k,x+(size/2)*z,size/2);
					}
				}
//				quadtree(y,x,size/2);
//				quadtree(y,x+size/2,size/2);
//				quadtree(y+size/2,x,size/2);
//				quadtree(y+size/2,x+size/2,size/2);
//				
				printf(")");
				return;
			}
			
		}
	}
	
	printf("%d",temp);
	
	
}

int main(int argc, char** argv) {
	
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]-='0';
		}
	}
	
	quadtree(0,0,n);


	return 0;
}

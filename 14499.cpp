#include <iostream>
using namespace std;
const int MAX=30;
int map[MAX][MAX]={0,};
int n,m,x,y,k;

typedef struct di{
	
	int r,c;
	int top,bottom,north,west,east,south;
	
	
}dices;

	void init(dices *dice)
	{
		dice->c=0;
		dice->r=0;
		
		dice->top=0;
		dice->bottom=0;
		dice->east=0;
		dice->west=0;
		dice->south=0;
		dice->north=0;
	}
	
	void gonorth(dices *dice)
	{
		dice->r=dice->r-1;
		
		int temp=dice->north;
		dice->north=dice->top;
		dice->top=dice->south;
		dice->south=dice->bottom;
		dice->bottom=temp;
		
		if(map[dice->r][dice->c]==0)
		{
			map[dice->r][dice->c]=dice->bottom;
		}
		else
		{
			dice->bottom=map[dice->r][dice->c];
			map[dice->r][dice->c]=0;
			
		}
		printf("%d\n",dice->top);
	}
	
		void gosouth(dices *dice)
	{
		dice->r=dice->r+1;
		
		int temp=dice->bottom;
		dice->bottom=dice->south;
		dice->south=dice->top;
		dice->top=dice->north;
		dice->north=temp;
		
		
		if(map[dice->r][dice->c]==0)
		{
			map[dice->r][dice->c]=dice->bottom;
		}
		else
		{
			dice->bottom=map[dice->r][dice->c];
			map[dice->r][dice->c]=0;
			
		}
		printf("%d\n",dice->top);
	}
		void goeast(dices *dice)
	{
		dice->c = dice->c+1;
		
		int temp=dice->top;
		dice->top=dice->west;
		dice->west=dice->bottom;
		dice->bottom=dice->east;
		dice->east=temp;
		
		if(map[dice->r][dice->c]==0)
		{
			map[dice->r][dice->c]=dice->bottom;
		}
		else
		{
			dice->bottom=map[dice->r][dice->c];
			map[dice->r][dice->c]=0;
			
		}
		printf("%d\n",dice->top);
	}
	
		void gowest(dices *dice)
	{
		
		
		dice->c=dice->c-1;
		
		int temp=dice->top;
		dice->top=dice->east;
		dice->east=dice->bottom;
		dice->bottom=dice->west;
		dice->west=temp;
		
		
		if(map[dice->r][dice->c]==0)
		{
			map[dice->r][dice->c]=dice->bottom;
		}
		else
		{
			dice->bottom=map[dice->r][dice->c];
			map[dice->r][dice->c]=0;
			
		}
		printf("%d\n",dice->top);
	}
	


int main(int argc, char** argv) {
	dices d;
	init(&d);
	cin>>n>>m>>x>>y>>k;
	
	d.r=x;
	d.c=y;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			printf("%d ",map[i][j]);
//		
//		}printf("\n");
//	}

	for(int i=0;i<k;i++)
	{
		
		int go;
		cin>>go;
		if(go==1)
		{
			if(d.c+1<m)
				goeast(&d);
				
		}
		else if(go ==2)
		{
			if(d.c>0)
				gowest(&d);
		
		}
		else if (go==3)
		{
			if(d.r>0)
				gonorth(&d);
		
		}
		else if (go==4)
		{
			if(d.r+1<n)
				gosouth(&d);
		
		}
		
		
	}
	
	return 0;
}

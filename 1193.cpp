#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char** argv) {


	int n;
	cin>>n;
	int index=1;
	for(int i=1; i<10000;i++)
	{
		int x,y;
		if(i%2==0)
		{
		
			y=1;
			int x=i;
		}
		else
		{
			y=i;
			x=1;
		}
		
		if(i%2==0)
		{
		
			for(int j=1;j<=i;j++)
			{
				
				if(index==n)
				{
					printf("%d/%d\n",y,x);
					return 0;
				}
		
				y++;
				x--;
				index++;
			}
		}
		else{
			for(int j=1;j<=i;j++)
			{
				
				if(index==n)
				{
					printf("%d/%d\n",y,x);
					return 0;
				}
		
				y--;
				x++;
				index++;
			}
			
		}
	
	
		
	}
	
	
	
	return 0;
}

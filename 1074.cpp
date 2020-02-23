#include <iostream>
#include <cmath>
using namespace std;
int n,r,c;
int cnt=0;
int ans=0;
int flag=0;
void go(int n,int y,int x)
{
	
		
		if(n==2)
		{
			if(y==r && x==c)
			{
				printf("%d\n",cnt);
				return;
			}
			cnt++;
			if(y==r && x+1==c)
			{
				printf("%d\n",cnt);
				return;
			}
			cnt++;
			if(y+1==r && x==c)
			{
				printf("%d\n",cnt);
				return;
			}
			cnt++;
			if(y+1==r && x+1==c)
			{
				printf("%d\n",cnt);
				return;
			}
			cnt++;
			return;
		
		}
		  
		
		
		go(n/2,y,x);
		go(n/2,y,x+n/2);
		go(n/2,y+n/2,x);
		go(n/2,y+n/2,x+n/2);
		
	
}


int main(int argc, char** argv) {
	cin>>n>>r>>c;

	go(pow(2,n),0,0);
	
	
	
	return 0;
}

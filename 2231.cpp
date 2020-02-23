#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans=0;
int main(int argc, char** argv) {

	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		int x=0;
		int y=i; 
		while(y>0)
		{	
//			printf("x: %d y:%d\n",x,y);
			x+=(y%10);
			y= y/10;
//			printf("%d\n",x);
		}
		
		if(x+i == n)
		{
			ans=i;
			printf("%d\n",i);
			break;
		}
		
//		printf("\n\n\n");
	}
		
		if(ans==0)
		printf("0");



	return 0;
}

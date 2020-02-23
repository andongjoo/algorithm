#include <iostream>
using namespace std;


int main(int argc, char** argv) {

	int n;
	cin>>n;
	
	for(int i=1;i<n;i++)
		printf(" ");
	printf("*\n");
	for(int i=2;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			printf(" ");
		}
		printf("*");
		
		for(int j=1;j<=i*2-3;j++)
		{
			printf(" ");
		}
		
	printf("*");
		printf("\n");	
	}
	if(n!=1)
	{
	
		for(int i=1;i<=n*2-1;i++)
			printf("*");
	}
	return 0;
}

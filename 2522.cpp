#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	int n;
	cin>>n;
	
	for(int j=1;j<=n;j++)
	{
		for(int i=n-j;i>=1;i--)
			printf(" ");
	
		for(int i=1;i<=j;i++)
			printf("*");
		printf("\n");
		
	}
	for(int j=1;j<n;j++)
	{
		for(int i=1;i<=j;i++)
			printf(" ");
			
		for(int i=n-j;i>=1;i--)
			printf("*");	
		printf("\n");	
	}
	
	
	return 0;
}

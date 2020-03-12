#include <iostream>
using namespace std;
int n;
int main(int argc, char** argv) {
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n-1;j++)
			printf(" ");
			
		for(int j=1;j<=2*i-1;j++)
			printf("*");
		printf("\n");
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=i;j++)
			printf(" ");
		for(int j=2*n-3;j>=i*2-1;j--)
			printf("*");
		printf("\n");
	}
	
	return 0;
}

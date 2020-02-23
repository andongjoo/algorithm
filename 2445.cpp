#include <iostream>
using namespace std;


int main(int argc, char** argv) {

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			printf("*");
		for(int j=2*n-2*i;j>0;j--)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
	for(int i=n-1;i>0;i--)
	{
		for(int j=i;j>0;j--)
			printf("*");
		
		for(int j=1;j<=n-i;j++)
			printf("  ");
		
		for(int j=i;j>0;j--)
			printf("*");
		printf("\n");
	}
	return 0;
}

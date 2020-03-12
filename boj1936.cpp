#include <iostream>
using namespace std;


int gcd(int a,int b)
{
	while(b)
	{
		a%b=r;
		a=a%b;
		b=b%r;
	}
	return a;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		printf("%d\n",a*b/gcd(a,b));		
	}

	return 0;
}

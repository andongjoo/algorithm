#include <iostream>
#include <string>
using namespace std;

long long int gcd(long long int a,long long int b)
{
	while(b)
	{
		long long int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(int argc, char** argv) {

	long long a,b;
	cin>>a>>b;
	
	for(int i=0;i<gcd(a,b);i++)
		printf("1");
	return 0;
}

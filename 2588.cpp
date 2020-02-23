#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	int k=b;
	int x,y,z;
	
	x=b/100;
	k%=100;
	y=k/10;
	k%=10;
	z=k;
	
	printf("%d\n%d\n%d\n%d",z*a,y*a,x*a,a*b);
	return 0;
}

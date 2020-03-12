#include <iostream>

using namespace std;

void bin(int n)
{
	if(n)
	{
		if(n%2==0)
		{	
			bin( -(n/2));
			
			printf("0");
		}else{
			bin(-(n-1)/2);
			printf("1");
		}
	}
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	if(n)
		bin(n);
	else
		printf("0");
	return 0;
}

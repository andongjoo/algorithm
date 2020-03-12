#include <iostream>

using namespace std;


int main(int argc, char** argv) {

	int n;
	cin>>n;
	
	while(n)
	{
		for(int i=2;i<=n;i++)
		{
			if( n%i==0)
			{
				printf("%d\n",i);
				n/=i;
				break;
			}
		}
		if(n==1)
			break;
	}
	
	return 0;
}

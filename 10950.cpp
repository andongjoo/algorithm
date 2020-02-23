#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	while(1)
	{
		int a,b;
		cin>>a>>b;
	
		if(a==0 &&  b==0)
			break;
			
		printf("%d\n",a+b);
	}
	return 0;
}

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		int a,b;
		cin>>a>>b;
		
		printf("Case #%d: %d\n",i,a+b);
	}
	return 0;
}

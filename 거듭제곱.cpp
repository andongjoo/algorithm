#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int pow(int a,int b)
{
	if(b==1)
	{
		return a;
	}else
	{
		return pow(a,b-1)*a;
	}
}
int main(int argc, char** argv) {
	
	for(int t=0;t<10;t++)
	{
		int test;
		cin>>test;
		int a,b;
		cin>>a>>b;
		
		printf("#%d %d\n",test+1,pow(a,b));
	}
	return 0;
}

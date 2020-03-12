#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int a[10000];

int main(int argc, char** argv) {
	for(int i=1;i<=10000;i++)
	{
		int temp=i;
		int sum=i;
		while(temp)
		{
			sum+=temp%10;
			temp/=10;
		}
		a[sum]=1;
	}
	for(int i=1;i<=10000;i++)
		if(a[i]!=1)
		printf("%d ",i);
	return 0;
}

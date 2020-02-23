#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char** argv) {

	int n;
	cin>>n;
	
	int a[10]={0};

	
	while(n>0)
	{
        a[n%10]++;
//		printf("%d\n",n);
		n/=10;
	}
//		
//	for(int i=0;i<10;i++)
//	{
//		printf("%d ",a[i]);
//	}printf("\n");
//	
	int cnt=1;
	
	for(int i=0;i<10;i++)
	{
		if(i!=6 && i!=9)
		{
//			printf("a[%d]: %d\n",i,a[i]);
			cnt=max(cnt,a[i]);
		}
	}
	
//	printf("%d\n",cnt);
	cnt=max (cnt,(a[6]+a[9]+1)/2);
	printf("%d\n",cnt);
	
	
	return 0;
}

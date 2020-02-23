#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	
	int a[10001]={0};
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
		
	for(int i=0;i<10001;i++)
	{
		for(int j=1;j<=a[i];j++)
			printf("%d\n",i);
	}
	
	return 0;
}

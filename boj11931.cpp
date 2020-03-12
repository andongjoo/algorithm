#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n;
int a[1000001];

bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	sort(a,a+n,cmp);
	
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}

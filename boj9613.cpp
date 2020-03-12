#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int gcd(int a,int b)
{
	while(b)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[101];
int main(int argc, char** argv) {
	
	
	int t;
	cin>>t;
	string str;
	for(int c=0;c<t;c++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		long long int sum=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				sum+=gcd(a[i],a[j]);
			}
		}
		printf("%lld\n",sum);
	}
	
	
	return 0;
}

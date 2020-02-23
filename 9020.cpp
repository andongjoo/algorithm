#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool prime(int n){
	
	if(n==2)
		return true;
	else{
		for(int i=2;i<=sqrt((double)n);i++)
		{
			if(n%i==0)
				return false;
		}	
	
	}
	return true;
	
}
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)
	{
		
		int n;
		cin>>n;
		int m=99999999;
		int first=9999999;
		int second=9999999;
		for(int i=2;i<=n/2;i++)
		{
			if(prime(i)&&prime(n-i)){
				first=i;
				second=n-i;
			}
			
		}
		printf("%d %d\n",first,second);
	}
	
	
	return 0;
}

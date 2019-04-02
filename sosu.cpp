//소수판별

#include <iostream>

using namespace std;



bool sosu(int n)
{
	if (n==1)
		return false;
	for (int i=2;i<n;i++)
	{
		
		if (n%i==0)
		{
			return false;
		}
	
	}
	return true;
}

int main() {

	
	int n,m;
	cin>> n>>m;
	int arr[m];
	for(int i=n;i<=m;i++)
	{
		
		if (sosu(i)==true) printf("%d ",i);
		
		
		
	}

	return 0;
}

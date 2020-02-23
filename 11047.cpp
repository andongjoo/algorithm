#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1000001;
int coin[MAX];
int n,k;
int sum=0;
int cnt=0;
int main(int argc, char** argv) {
	
	cin>>n>>k;
	
	
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	
	
	for(int i=n-1;i>=0;i--)
	{
		while(1)
		{
//			printf("%d\n",k);
			if(k>=coin[i])
			{
				k-=coin[i];
				cnt++;
			}
			else if(k<coin[i])
					break;
		
		}
		
		if(k==0)
			break;
	
	}
	
	printf("%d",cnt);
	
	return 0;
}

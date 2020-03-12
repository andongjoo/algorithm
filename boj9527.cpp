#include <iostream>
using namespace std;
int n,m;

int main(int argc, char** argv) {
	
	int cnt=0;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		int temp=i;
		while(temp)
		{
			if(temp%2==1)
			{
				cnt++;
			}
			temp/=2;
		}
	}
	printf("%d",cnt); 
	return 0;
}

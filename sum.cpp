#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
	int ans;
	int arr[100][100];
int main(int argc, char** argv) {

	for(int t=1;t<=10;t++)
	{
		 ans=0;
		int num;
		cin>>num;
        memset(arr, 0, sizeof(int)*100*100);
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				cin>>arr[i][j];
			}
		}
		int sum=0;
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				sum+=arr[i][j];
			}
			ans=max(sum,ans);
			sum=0;
		}		
		
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				sum+=arr[j][i];
			}
			ans=max(sum,ans);
			sum=0;
		}	
			
		sum=0;
		for(int i=0;i<100;i++)
		{
			sum+=arr[i][i];
		}
		ans=max(sum,ans);
		sum=0;
		for(int i=0;i<100;i++)
		{
			sum+=arr[i][99-i];
		}
		ans=max(sum,ans);
		
		printf("#%d %d\n",num,ans);
	}
	return 0;
}

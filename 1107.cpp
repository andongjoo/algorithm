#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int a[11]={0};
int num=99999999;

int get_cnt(int k)
{

	int cnt=0;
	if(k==0)
	{
		if(a[k]==1)
			return 0;
		else
			return 1;
	}
	
	while(k)
	{
		
		if(a[k%10]==1)
		{
			return 0;
		}
		cnt++;
		k/=10;
		
	}


	return cnt;	
}




int main(int argc, char** argv) {

	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{	int x;
		cin>>x;
		a[x]=1;
	}

		
	for(int i=0;i<=1000000;i++)
	{
		int k=get_cnt(i);
//		printf("ÇöÀç %d %d\n",i,k);
		if(k)
		{
			k += abs(n-i);
			num=min(num,k);
		}
		 
		num=min(num,abs(n-100));
	
		
	}
		printf("%d",num);

	return 0;	
}

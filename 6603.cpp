#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n=1;

int a[20]={0};
vector<int> check;

void go(int index,int cnt)
{
	
	if(cnt==6)
	{
		for(int i=0;i<n;i++)
		{
			if(check[i])
				printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	
	
	if(n-index<6-cnt)
		return;
	
	check[index]=1;
	go(index+1,cnt+1);
	check[index]=0;
	go(index+1,cnt);
	

	
}


int main(int argc, char** argv) {

	
	while(true)
	{
		
		cin>>n;
		
		memset(a,0,sizeof(a));
		check=vector<int>(n,0);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			cin>>a[i];
	
		go(0,0);
			
		
	
	
	
	
	
		printf("\n");
	}
	
	
	
	
	return 0;
}

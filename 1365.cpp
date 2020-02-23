#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int MAX=100001;
int a[MAX]={0};
int b[MAX]={0};
int ans=0;
int lower_bound(int s,int e,int value)
{
	while(s<=e)
	{
		int mid = (s+e)/2;
		
		if(b[mid]>=value)
			e=mid-1;
		else
			s=mid+1;
		
	}
	return s;
}

int main(int argc, char** argv) {
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int index=1;
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(b[index-1]<a[i])
		{
			b[index]=a[i];
			index++;
			
		}
		else
		b[lower_bound(0,index-1,a[i])]=a[i];
		
	}
	
	printf("%d",n-index);
	
	return 0;
}

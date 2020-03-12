#include <iostream>
#include <algorithm>
using namespace std;
int a[10+1];

bool cmp(int a,int b)
{
	return a>b;
}

int main(int argc, char** argv) {

	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	int index=0;
	int cnt=0;
	sort(a,a+n,cmp);
	while(k)
	{
		if( a[index]<=k)
		{
			k-=a[index];
			cnt++;
			continue;
		}
		index++;
	}
	printf("%d",cnt);
	

	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	
	int cnt5=0;
	int cnt2=0;
	
	
	for(long long i=5;i<=n;i*=5)
	{
		cnt5 += n/i;
	}for(long long i=2;i<=n;i*=2)
	{
		cnt2 += n/i;
	}
	
	for(long long i=5;i<=(n-m);i*=5)
	{
		cnt5 -= (n-m)/i;
	}
	
	for(long long i=2;i<=(n-m);i*=2)
	{
		cnt2 -= (n-m)/i;
	}
	for(long long i=5;i<=m;i*=5)
	{
		cnt5 -= m/i;
	}
	
	for(long long i=2;i<=m;i*=2)
	{
		cnt2 -=m/i;
	}

	
	printf("%d",min(cnt5,cnt2));
	return 0;
}

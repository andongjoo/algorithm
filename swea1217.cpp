#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int pow(int n,int m)
{
	if(m==1)
		return n;
	else
		return n*pow(n,m-1);
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for(int i=1;i<=10;i++)
	{
		
		int tc;
		cin>>tc;
		
		int a,b;
		cin>>a>>b;
		ans=pow(a,b);
		
		printf("#%d %d\n",i,ans);
	}

	return 0;
}

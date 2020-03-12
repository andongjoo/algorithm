#include <iostream>
using namespace std;

int n,m,k;
int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	
	int team=0;
	
	while(n>1 && m>0)
	{
			
				n-=2;
				m--;
				team++;
		
	}
	
	k-=m;
	k-=n;
	
	while(k>0)
	{
		team--;
		k-=3;
	}
	printf("%d",team);
	
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,dir,subdir;
const int MAX=1000001;
int a[MAX];
long long int dp[MAX];

int main(int argc, char** argv) {

	cin>>n;
	for(int i=0;i<n;i++)
	{
			cin>>a[i];
	}

	long long int cnt=0;
	cin>>dir>>subdir;
	

	
	
	
	for(int i=0;i<n;i++)
	{
		a[i]-=dir;
		cnt++;
		
		if(a[i]<=0)
			continue;
		else{
			
			if(a[i]%subdir==0)
			{
				cnt+= (a[i]/subdir);
			}else{
				cnt+=(a[i]/subdir)+1;
			}
			
		}
		
	}
	printf("%lld",cnt);
	
	return 0;
}

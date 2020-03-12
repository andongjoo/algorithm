#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
const int MAX=1000;
int a[MAX];

int check(int index)
{
	int ans=max(a[index-2],a[index-1]);
	ans=max(ans,max(a[index+1],a[index+2]));
	
	if(a[index]>ans)
	{
		return a[index]-ans;
	}
	return 0;
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for(int t=1;t<=10;t++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		long long sum=0;	
		for(int i=2;i<n-2;i++)
		{
			sum+=check(i);
		}
		
		cout<<"#"<<t<<" "<<sum<<"\n";
		
	}

	return 0;
}

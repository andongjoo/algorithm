#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=100000+1;
int n;
int a[MAX];
bool check[MAX];
long long ans;
long long sum;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		
			cin>>a[i];
			sum+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		ans+=	a[i]*(sum-a[i]);
	}
	cout<<ans/2;
	
	return 0;
}

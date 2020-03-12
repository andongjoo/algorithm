#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10;
int m,n,k,x,y;
int a[MAX];
int b[MAX];
int t[1001];
int tc;
int ans;
vector<int> v;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		cin>>n>>m>>k>>x>>y;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			cin>>b[i];
		for(int i=0;i<k;i++)
			cin>>t[i];
			
			
		printf("#%d %d\n",t,ans);
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ans=0;
vector<int> v;
bool check[8];
void go(int index,vector<int> &a)
{
	if(index>=n)
	{
		int sum=0;
		for(int i=0;i<n-1;i++)
			sum+=abs(a[i]-a[i+1]);
		ans=max(sum,ans);
		return;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!check[i])
		{
			check[i]=true;
			a.push_back(v[i]);
			go(index+1,a);
			a.pop_back();
			check[i]=false;
		}
	}
}

int main(int argc, char** argv) {

	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);	
	}
	int sum=0;
	
	
	vector<int> a;
	go(0,a);
	cout<<ans;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,c;
vector<int> v;
int result;
bool check(int mid)
{
	int cnt=1;
	int index=v[0];
	
	for(int i=1;i<n;i++)
	{
		if(v[i]-index>=mid)
		{
			cnt++;
			index=v[i];
		}
	}
	
	if(cnt>=c)
		return true;
	
	return false;
	
}

int main(int argc, char** argv) {
	cin>>n>>c;
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	
	
	int start=1;
	int end=v.back()-v.front();
	result=0;
	while(start<=end)
	{
		int mid =(start+end)/2;
		if(check(mid))
		{
			start=mid+1;
			result=max(result,mid);
			
		}else
		{
			end=mid-1;
		}
	}
	cout<<result;
	
	return 0;
}

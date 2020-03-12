#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans=2100000000;
bool cmp(int a,int b)
{
	return a<b;
}

bool cmp2(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	int n;
	cin>>n;
	vector<int> v;
	vector<int> v2;
	vector<int> v3;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v2.push_back(x);
	}
	int sum=0;
	sort(v.begin(),v.end(),cmp2);
	sort(v2.begin(),v2.end(),cmp);
	for(int i=0;i<n;i++)
	{
		sum+= v[i]*v2[i];
	}
	printf("%d",sum);

	
	
	return 0;
}

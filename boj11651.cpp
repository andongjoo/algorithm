#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int n;
vector<pair<int,int> > v;

bool cmp( pair<int,int> a,pair<int,int> b)
{
	if(a.second==b.second)
	{
		return a.first<b.first;
	}else
		return a.second<b.second;
}

int main(int argc, char** argv) {

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	
	sort(v.begin(),v.end(),cmp);

	for(int i=0;i<n;i++)
		printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}

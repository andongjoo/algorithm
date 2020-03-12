#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[50+1];

int main(int argc, char** argv) {
	vector<pair<int,int> > v;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int h,w;
		cin>>w>>h;
		v.push_back(make_pair(w,h));
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i].first>v[j].first)
			{
				if(v[i].second>v[j].second)
				{
					a[j]++;
				}
			}
			
			if(v[i].first<v[j].first)
			{
				if(v[i].second<v[j].second)
				{
					a[i]++;
				}
			}
			
			
		}
	}

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]+1);
	}
//		for(int i=0;i<n;i++)
//	{
//		printf("%d ",v2[i]);
//	}
	
	return 0;
}

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	vector < pair<int,string> > v(n);
	
	for(int i=0;i<n;i++)
	{
		
		cin>>v[i].second;
		v[i].first=v[i].second.size();
	}
	
	sort(v.begin(),v.end());
	


	for(int i=0;i<n-1;i++)
	{
	
		if(v[i].second==v[i+1].second)
		{
			v.erase(v.begin()+i);
			n--;
			i--;
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<v[i].second<<endl;
	}

	return 0;
}

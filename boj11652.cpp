#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

int main(int argc, char** argv) {
	map<long long,int> m;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		m[a]++;
	}
	int cnt=0;
	long long card=0;
	for(auto it=m.begin(); it !=m.end();it++)
	{
		if (cnt==it->second)
		{
			if(card>it->first)
			{
				card=it->first;
				cnt=it->second;
			}
		}
		else if(cnt<it->second)
		{
			card=it->first;
			cnt=it->second;
		}
	}
	cout<<card;
	return 0;
}

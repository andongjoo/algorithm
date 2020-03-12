#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	vector<int> p;
	vector<int> t;
	for(int i=0;i<n;i++)
	{
		int tm;
		cin>>tm;
		p.push_back(tm);
	}
	sort(p.begin(),p.end());
	int time=0;
	int cnt=n;
	for(int i=0;i<n;i++)
	{
		time+=(cnt*p[i]);
		cnt--;
	}
	printf("%d",time);
	
	return 0;
}

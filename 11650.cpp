#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin.tie(NULL); 
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	vector<pair<int,int> > v;
	for(int i=0;i<t;i++)
	{
	
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++)
	{
		printf("%d %d\n",v[i].first,v[i].second);
	}
	
	
		return 0;
}

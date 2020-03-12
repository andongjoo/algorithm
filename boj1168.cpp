#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	int n,k;
	vector<int> v;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		v.push_back(i+1);
	}
	int cur=0;
	printf("<");
	while(!v.empty())
	{
		cur+=k-1;
		
		if(cur>=v.size())
		{
			cur%=v.size();
		}
		if(v.size()!=1)
			printf("%d, ",v[cur]);
		else
			printf("%d>",v[cur]);
		v.erase(v.begin()+cur);
	}
	
	return 0;
}

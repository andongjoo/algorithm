#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int> > v;
int n;

void hanoi(int n,int from,int temp,int to)
{
	if(n==1)
	{
		v.push_back(make_pair(from,to));
	}
	else{
		hanoi(n-1,from,to,temp);
		v.push_back(make_pair(from,to));
		hanoi(n-1,temp,from,to);
	}
	
}

int main(int argc, char** argv) {
	cin>>n;
	
	
	hanoi(n,1,2,3);
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)
		printf("%d %d\n",v[i].first,v[i].second);
	

	return 0;
}

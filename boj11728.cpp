#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(int argc, char** argv) {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n+m;i++)
	{
		int num;
		cin>>num;
		a.push_back(num);
		
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	return 0;
}

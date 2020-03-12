#include <iostream>
#include <vector>
#include <algorithm>
using namespace;
const int MAX=100;
int n,l,r;
int a[MAX][MAX];
int main(int argc, char** argv) {
	cin>>n>>l>>r;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	return 0;
}

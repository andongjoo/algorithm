#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAX=10000+1;
int n;
int a[MAX];


int main(int argc, char** argv) {

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	if(next_permutation(a,a+n))
	{
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
	}else{
		printf("-1");
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	printf("%d",v[k-1]);
	return 0;
}

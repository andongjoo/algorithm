#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=500001;
int card[MAX]={0};
int a[MAX]={0};
int n,m;


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
	 cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>card[i];
	}
	sort(card,card+n);
	
	cin>>m;
	for(int j=0;j<m;j++)
	{
		int number;
		cin>>number;
		
		printf("%d ",upper_bound(card,card+n,number)-lower_bound(card,card+n,number));
	}
	
	return 0;
}

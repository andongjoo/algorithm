#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int pizza;
	cin>>pizza;
	int m,n;
	cin>>m>>n;
	
	vector<int> a(m),b(n);
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
		
	int sum=0;
	
	vector<int> v1(1,0),v2(1,0);
	int low=0,high=0;
	
	while(low<a.size())
	{
		sum+=a[high++];
		if(sum<=pizza)
			v1.push_back(sum);
		else{
			low++;
			high=low;
			sum=0;
		}
		
		if(high==a.size())
			high=0;
		
		if( (!low && !high) || high+1==low )
		{
			low++;
			high=low;
			sum=0;
		}
		
	}
	
	low=0,high=0,sum=0;
	
	while(low<b.size())
	{
		sum+=b[high++];
		if(sum<=pizza)
			v2.push_back(sum);
		else{
			low++;
			high=low;
			sum=0;
		}
		if(high==a.size())
			high=0;
		
		if( (!low && !high) || high+1==low )
		{
			low++;
			high=low;
			sum=0;
		}
		
			
	}
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int res=0;
	for(int i=0;i<v1.size();i++)
	{
		int low = lower_bound(v2.begin(),v2.end(),pizza-v1[i])-v2.begin();
		int high=upper_bound(v2.begin(),v2.end(),pizza-v1[i])-v2.begin();
		res+=high-low;			
	}		
	printf("%d",res);	

	return 0;
}

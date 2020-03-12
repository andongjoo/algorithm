#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[4000001];
int n;

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	for(int i=0;i<=4000000;i++)
	{
		a[i]=i;
	}
	for(int i=2;i<=4000000;i++)
	{
		if(a[i]==0)
			continue;
			
		for(int j=i+i;j<=4000000;j+=i)
		{
			a[j]=0;
		}
	}
	
	cin>>n;
	vector<int> v;
	if(n==1)
	{
		printf("0");
		return 0;
	}
	
	for(int i=2;i<=4000000;i++)
		if(a[i])
			v.push_back(a[i]);
			
	int left=0;
	int right=0;
	int sum=v[0];
	int ans=0;
	while(1)
	{
		if(right==v.size())
			break;
		
//		printf("sum:%d left: %d right:%d\n",sum,left,right);	
		if(sum<n)
		{
			sum+=v[++right];
		}else if (sum==n)
		{
			ans++;
			sum-=v[left++];
			
		}else{
			
			sum-=v[left++];
		}
		
	}
	
	printf("%d",ans);
	return 0;
}

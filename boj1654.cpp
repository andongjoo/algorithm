#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> v;
int k,n;
long long check(long long mid){
	long long cnt=0;
	for(int i=0;i<v.size();i++)
	{
		cnt+=v[i]/mid;
	}
	return cnt;
}

long long binary(long long start,long long end)
{
	long long mid;
	long long result=0;
	while(start<=end)
	{
		
		mid=(start+end)/2;
//		printf("mid:%d cnt:%d \n",mid,check(mid));
		if(	n>check(mid) )
		{
			end=mid-1;
		}else if(n<=check(mid)){
			start=mid+1;
			
			if(mid>result)
			{
				result=mid;
			}
		}
		
	}
	return result;
}

int main(int argc, char** argv) {
	
	cin>>k>>n;
	long long end=0;
	long long  start=1;
	for(int i=0;i<k;i++)
	{
		long long l;
		cin>>l;
		v.push_back(l);	
		end=max(end,l);
	}
	
	long long ans=binary(start,end);
	cout<<ans;
	return 0;
}

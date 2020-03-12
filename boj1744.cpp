#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10000+1;
int n;
int a[MAX];

bool cmp(int a,int b)
{
	if( a>=0 && b>=0)
		return a>b;
	else 
		return a<b;
}
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	vector<int> plus;
	vector<int> minus;
	vector<int> zero;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x>0)
			plus.push_back(x);
		else if(x<0)
			minus.push_back(x);
		else
			zero.push_back(x);
	}
	
	sort(plus.begin(),plus.end(),cmp);
	sort(minus.begin(),minus.end(),cmp);
	
//	for(int i=0;i<plus.size();i++)
//		printf("%d ",plus[i]);
//	printf("\n");
//	for(int i=0;i<minus.size();i++)
//		printf("%d ",minus[i]);
//	printf("\n");
	
	int sum=0;
	
	for(int i=0;i<plus.size();i+=2)
	{
		if(plus.size()%2==1 && plus.size()-1==i)
		{
			sum+=plus[i];
		}else
		{
			if(plus[i]*plus[i+1]>plus[i]+plus[i+1])
				sum+=plus[i]*plus[i+1];
			else
				sum+= (plus[i]+plus[i+1]);
		}
		
//		printf("index:%d sum:%d\n",i,sum);
	}
	
	for(int i=0;i<minus.size();i+=2)
	{
		if(minus.size()%2==1 && minus.size()-1==i)
		{
			if(zero.size()>=1)
				sum+=0;
			else
				sum+=minus[i];
		}else
		{
			sum+=minus[i]*minus[i+1];
			
		}
//		printf("index:%d sum:%d\n",i,sum);
		
	}
	printf("%d",sum);
	
	return 0;
}

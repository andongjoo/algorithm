#include <iostream>
#include <algorithm>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

bool cmp(int a,int b)
{
	return abs(a)>abs(b);
}
int main(int argc, char** argv) {
	
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	int flag=2100000000;
	sort(v.begin(),v.end(),cmp);
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		if(abs(v[i]+v[i+1])<flag)
		{
			flag=abs(v[i]+v[i+1]);
			if(v[i]>v[i+1])
			{
				a=v[i+1];
				b=v[i];
			}else
			{
				a=v[i];
				b=v[i+1];
			}
		}
		
	}
	
	
	printf("%d %d",a,b);
		
	return 0;
}

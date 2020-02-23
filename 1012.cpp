#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{

	int n=10;
	vector<int> v;
	int flag=1;
	for(int i=1;i<20;i++)
	{
//		printf("%d\n",i);
		int sum=i;
		for(int j=i+1;j<=20;j++)
		{
			
//		printf("j: %d\n",j);
			sum= sum * j;
			v.push_back(sum);
		
			
		}
		
		
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
	return 0;
	
}

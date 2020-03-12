#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=101;
int a[MAX];



int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		for(int i=0;i<=100;i++)
			a[i]=0;
		
		int test;
		cin>>test;
		
		
		for(int i=0;i<1000;i++)
		{
			int grade;
			cin>>grade;
			a[grade]++;
		}
		
		int max_num=0;
		int index;
		for(int i=0;i<=100;i++)
		{
			if(max_num<=a[i])
			{
				max_num=a[i];
				index=i;
			}
		}
		
		printf("#%d %d\n",test,index);
	}

	return 0;
}

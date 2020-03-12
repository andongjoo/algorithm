#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
using namespace std;


int N;
int a[1000];
int main(int argc, char** argv) {
	
	for(int tc=1;tc<=10;tc++)
	{
		memset(a,0,sizeof(a));
		cin>>N;	
		int answer=0;	
		for (int i = 0; i < N; i++)
			cin>>a[i];
		
		
		for(int i=2;i<N-2;i++)
		{
			int flag=0;
			for(int j=-2;j<=2;j++)
			{
				if( i+j !=i)
				{
					flag=max(flag,a[i+j]); 
				}
			}
			if( a[i]-flag>0)
			{
				answer+=a[i]-flag;
			}
		}
		
		printf("#%d %d\n",tc,answer);
	}
	
	return 0;
}

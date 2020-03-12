#include <iostream>
#include <algorithm>
using namespace std;



int len(int x1,int y1,int x2,int y2)
{
	
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main(int argc, char** argv) {
	int tc;
	cin>>tc;
	
	for(int t=0;t<tc;t++)
	{
		int x1,x2,y1,y2;
		
		cin>>x1>>y1>>x2>>y2;
		int n;
		cin>>n;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			int x,y,r;
			cin>>x>>y>>r;
			int flag1=0,flag2=0;
			flag1 = r*r>len(x1,y1,x,y) ? 1:0;
			flag2 = r*r>len(x2,y2,x,y) ? 1:0;
			if(flag1!=flag2)
				cnt++;
		}
		
		printf("%d\n",cnt);
	}

	return 0;
}

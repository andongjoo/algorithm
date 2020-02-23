#include <iostream>
using namespace std;
const int MAX=10001;
int a[MAX]={0};

int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	
	int num=1;
	int cur=666;
	
	while(1)
	{
		if(n==num)
			break;
			
		cur++;
		int temp=cur;
		
		
		int flag=0;
		while(temp)
		{
			int x=temp%10;
			if(x==6)
				flag++;
			else if (flag<3)
				flag=0;
			temp/=10;
		}
		
		if(flag>=3)
			num++;
		
	
	
	
		
	}
	
	printf("%d",cur);
	
	
	return 0;
}

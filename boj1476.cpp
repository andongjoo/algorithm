#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	int e,s,m;
	cin>>e>>s>>m;
	
	
	int a=1,b=1,c=1;
	int index=1;
	while(1)
	{
		if(a==e && b==s && c==m)
		{
			printf("%d",index);
			break;
		}
		a++;
		b++;
		c++;
		index++;
		if(a>15)
			a=1;
		if(b>28)
			b=1;
		if(c>19)
			c=1;
	}
	
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	string str;
	int a[4];
	while(getline(cin,str))
	{
		for(int i=0;i<4;i++)
			a[i]=0;
			
			
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			{
				a[0]++;	
			}else if(str[i]>='A'&&str[i]<='Z')
			{
				a[1]++;	
			}else if(str[i]>='0'&&str[i]<='9')
			{
				a[2]++;	
			}else
			{
				a[3]++;
			}
		}
		for(int i=0;i<4;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	

	return 0;
}

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int t;
char str[21];
int main(int argc, char** argv) {
	cin>>t;
	while(t--)
	{
		memset(str,0,sizeof(str));
		int n;
		cin>>n;
		scanf("%s",&str);
		for(int i=0;i<sizeof(str);i++)
		{
			if(str[i]!=0)
			{
				for(int j=0;j<n;j++)
				{
					printf("%c",str[i]);
				}
			}
		}
		printf("\n");
	}

	return 0;
}

#include <iostream>
#include<string.h>
#include <algorithm>
using namespace std;

char str[101];
int arr[123]={0};
int main(int argc, char** argv) {
	//97 ~ 122
	scanf("%s",&str);
	memset(arr,-1,sizeof(arr));
	for(int i=0;i<sizeof(str);i++)
	{
		
		if(str[i]>=97 && str[i]<=122&& arr[str[i]]==-1)
		{
			arr[str[i]]=i;
		}
	}

	for(int i=97;i<=122;i++)
		printf("%d ",arr[i]);
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main(int argc, char** argv) {

	int cnt=0;
	string str;
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
//		printf("%d\n",i);
		if(str[i]=='c'&& str[i+1]=='=')
		{
				i++;
				cnt++;	
		}	
		else if (str[i]=='c'&&str[i+1]=='-')
		{		i++;
				cnt++;

		}
		else if(str[i]=='d'&&str[i+1]=='z'&&str[i+2]=='=')
		{
					i+=2;
					cnt++;
		}
		else if(str[i]=='d'&&str[i+1]=='-')
		{
			i++;
				cnt++;
		}
		else if(str[i]=='l'&&str[i+1]=='j')
		{
			i++;
				cnt++;
		}
		else if(str[i]=='n'&&str[i+1]=='j')
		{
				i++;
				cnt++;
		}
		else if(str[i]=='s'&&str[i+1]=='=')
		{
			i++;
				cnt++;
		}
		else if(str[i]=='z'&&str[i+1]=='=')
		{
			i++;
				cnt++;
		}
		else
			cnt++;
		
		
		
		
	}
	
	printf("%d",cnt);
	return 0;
}

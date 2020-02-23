#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char** argv) {

	string str;
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		if(str[i]<=90 && str[i]>=65)
			printf("%c",str[i]);
	}

	return 0;
}

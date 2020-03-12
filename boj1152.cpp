#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	
	string s="";
	getline(cin,s);
	int cnt=1;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==' ')
			cnt++;
	}
	if(s[s.size()-1]==' ')
		cnt--;
	printf("%d",cnt);
	return 0;
}

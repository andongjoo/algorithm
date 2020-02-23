#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	
	int t;
	cin>>t;
	while(t--)
	{
		char str[4];
		
		cin>>str;
		cout<<str[0]-'0'+str[2]-'0'<<endl;
//		cout<<str;
	}
	return 0;
}

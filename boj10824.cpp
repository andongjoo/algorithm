#include <iostream>
#include <algorithm>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {

	int a,b,c,d;
	string s;
	string s2;
	
	cin>>a>>b>>c>>d;
	
	s=to_string(a)+to_string(b);
	s2=to_string(c)+to_string(d);
	
	cout<<stoll(s)+stoll(s2);
	return 0;
}

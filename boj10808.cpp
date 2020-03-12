#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string str;
	cin>>str;
	int arr[26];
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		arr[i]=0;
	for(int i=0;i<str.size();i++)
	{
		char c=str[i]-'a';
		arr[c]++;
//		printf("%d ",c);
	}
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		printf("%d ",arr[i]);
	
	return 0;
}

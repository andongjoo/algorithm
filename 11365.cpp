#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	
	while(1)
	{
		string str;
		getline(cin,str);
		
		if(str=="END")
			break;
		
		reverse(str.begin(),str.end());
//		for(int i=0;i<sizeof(str)/2;i++)
//		{
//			
//			char temp=str[i];
//			str[i]=str[sizeof(str)-i-1];
//			str[sizeof(str)-1-i]=temp;
//		}
		cout<<str<<endl;	
	}
	
	return 0;
}

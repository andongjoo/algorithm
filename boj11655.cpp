#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			if(s[i] +13 >'z')
			{
				s[i]= (s[i]+12)%'z'+'a';
				
			}
			else
				s[i]+=13;
		}else if(s[i]>='A' && s[i]<='Z')
		{
			
			if(s[i] +13 >'Z')
			{
				s[i]= (s[i]+12)%'Z'+'A';
				
			}
			else
				s[i]+=13;		}	
	}
	cout<<s;
//	for(int i=0;i<s.size();i++)
//		printf("%d ",s[i]);
//	printf("\n%d %d %d",'z','a','z'%'a'+'a');
	return 0;
}

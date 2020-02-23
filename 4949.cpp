#include <iostream>
#include <stack>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	stack<char> s;
	string str;
	while(1)
	{
		while(!s.empty())
		{s.pop();}
		
		getline(cin,str);

		if(str[0]=='.')
			break;
		
		int flag=1;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='(' || str[i]=='[')
				s.push(str[i]);
		
			else if(str[i]==')')
			{
				
				if(!s.empty() && s.top()=='(')
				{
					s.pop();
				}
				else
				{
					flag=0;
					break;
				}
			}
			else if (str[i]==']')
			{
				if(!s.empty() && s.top()=='[')
				{
					s.pop();
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		
		
		if(s.empty() && flag)
			printf("yes\n");
		else
			printf("no\n");		
	}	

	
	return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(int argc, char** argv) {
	stack<char> s;
	string str;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		while(!s.empty())
		{
			s.pop();
		}
		cin>>str;
		bool flag=true;
		for(int j=0;j<str.length();j++)
		{

			if(str[j]=='(')
			{
				s.push(str[i]);
			}
			else if (!s.empty() && str[j]==')')
			{
				s.pop();
			}else if (s.empty()&& str[j]==')')
			{
				flag=false;
			}
			
		}
		
		if(!flag || !s.empty())
			printf("NO\n");
		else
			printf("YES\n");
		
		
	}

	return 0;
}

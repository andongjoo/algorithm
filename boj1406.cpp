#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


int main(int argc, char** argv) {
	string s;
	cin>>s;
	int n;
	cin>>n;
	int cur=s.size();
	stack<char> l,r;
	for(int i=0;i<s.size();i++)
	{
		l.push(s[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>c;
		if(c=='P')
		{
			char ch;
			cin>>ch;
			l.push(ch);
		}else if (c=='B')
		{
			if(!l.empty())	
			{
				l.pop();
			}
		}
		else if (c=='D')
		{
			
			if(!r.empty())
			{
				l.push(r.top());
				r.pop();
			}	
		}
		else if (c=='L')
		{
			if(!l.empty())
			{
				r.push(l.top());
				l.pop();
			}
		}
	}
	
	while(!l.empty())
	{
		r.push(l.top());
		l.pop();
	}
	
	while(!r.empty())
	{
		printf("%c",r.top());
		r.pop();
	}
	
	return 0;
}

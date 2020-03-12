#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int ans;
int n;
stack<char> s;
		
int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for(int t=1;t<=10;t++)
	{
		cin>>n;
		string str="";
		cin>>str;
		while(!s.empty())
			s.pop();
		
		int idx=0;
		for(int i=0;i<n;i++)
		{
			idx++;
			if(str[i]=='(' || str[i]=='[' || str[i]=='<' || str[i]=='{')
				s.push(str[i]);
			else if (str[i]==')')
			{
				if(s.top()=='(')
					s.pop();
				else{
					ans=0;
					break;
				}
			}
			else if (str[i]==']')
			{
				if(s.top()=='[')
					s.pop();
				else{
					ans=0;
					break;
				}
			}else if (str[i]=='>')
			{
				if(s.top()=='<')
					s.pop();
				else{
					ans=0;
					break;
				}
			}else if (str[i]=='}')
			{
				if(s.top()=='{')
					s.pop();
				else{
					ans=0;
					break;
				}
			}
		}
		
		if(s.empty() &&idx==n)
			ans=1;
		else
			ans=0;
		printf("#%d %d\n",t,ans);
	}

	return 0;
}

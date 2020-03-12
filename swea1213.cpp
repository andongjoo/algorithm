#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int ans;
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	
	for(int t=1;t<=10;t++)
	{
		int tn;
		cin>>tn;
		
		string s;
		cin>>s;
		string str;
		cin>>str;
		ans=0;
		
		int l=s.length();
		for(int i=0;i<str.length()-l+1;i++)
		{
			string temp=str.substr(i,l);
			cout<<temp<<"\n";
			if(temp==s)
				ans++;
		}
		
	
		
		printf("#%d %d\n",tn,ans);
	}

	return 0;
}

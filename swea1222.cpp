#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<char> v;
int ans;
int n;
stack<int> s1;
stack<char> s2;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	
	for(int t=1;t<=10;t++){
		

		string str;
		ans=0;
		cin>>n;
		cin>>str;
		
		
		for(int i=0;i<n;i++)
		{
			if(str[i]>='0' && str[i]<='9')
				ans+=str[i]-'0';
			
		}
	
		
		printf("#%d %d\n",t,ans);
	}
	

	return 0;
}

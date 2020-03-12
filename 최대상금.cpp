#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
using namespace std; 

int t;
int answer;
int n,k;
bool check[7];
string s;
void dfs(int index,int cnt,string str)
{
	
	if(cnt==k)
	{
		answer=max(answer,stoi(str));
		return;
	}
	
	
	for(int i=index;i<str.size();i++)
	{
		for(int j=i;j<str.size();j++)
		{
			if(str[i]<=str[j] && i!=j)
			{
				swap(str[i],str[j]);
				dfs(i,cnt+1,str);
				swap(str[i],str[j]);
			}
		}
	}
	
}

int main(int argc, char** argv) {
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		answer=0;
		cin>>n>>k;
		string s=to_string(n);
		dfs(0,0,s);
		printf("#%d %d\n",test,answer);
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
bool cmp(string s1,string s2)
{
	int index=0;
	while(1)
	{
		if(index==s1.length())
			return true;
		else if (index==s2.length())
			return false;
		
		if(s1[index]>s2[index])
		{
			return false;
		}else if (s1[index]<s2[index])
		{
			return true;
		}
		
		index++;
	}
}
int main(int argc, char** argv) {
	
	vector<string> v;
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++)
	{
		string sub=s.substr(i,s.size());
		v.push_back(sub);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	return 0;
}

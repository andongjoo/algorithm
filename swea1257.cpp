#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int tc,ans,k;
vector<string> v;
map<string,int> m;

int main(int argc, char** argv) {
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		cin>>k;
		
		string str;
		cin>>str;
		v.clear();
		m.clear();
		for(int i=0;i<str.length();i++)
		{
			for(int j=1;j<=str.length();j++)
			{
				if(j+i<=str.length())
				{
					string sub=str.substr(i,j);
//					cout<<sub<<endl;
//					v.push_back(sub);
					m[sub]++;	
				}
			}
		}
		int cnt=0;
		for(auto it=m.begin();it!=m.end();it++)
		{
//			cnt++;
//			cout<<it->first<<endl;
			string sub=it->first;
			v.push_back(sub);
		}
//		for(int i=0;i<v.size();i++)
//			cout<<v[i]<<endl;
//		printf("cnt:%d\n",cnt);
		
		sort(v.begin(),v.end());
	
//		for(int i=0;i<v.size();i++)
//			cout<<v[i]<<"\n";	
		
		if(v.size()>=k)
			cout<<"#"<<t<<" "<<v[k-1]<<"\n";
		else
			cout<<"#"<<t<<" none\n";
	
	}

	return 0;
}

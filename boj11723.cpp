#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> v;
int n;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n;
	
	string str="";
	for(int i=0;i<n;i++)
	{
		cin>>str;
		if(str=="add")
		{
			int x;
			cin>>x;
			bool flag=false;
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==x)
				{
					flag=true;
				}
			}
			if(!flag)
				v.push_back(x);
			
		}else if (str=="remove")
		{
			int x;
			cin>>x;
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==x)
				{
					for(int k=j;k<v.size()-1;k++)
						v[k]=v[k+1];
					v.pop_back();
				}
			}
			
		}else if (str=="check"){
			
			int x;
			cin>>x;
			bool flag=false;
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==x)
				{
					flag=true;
				}
			}
			if(flag)
				printf("1\n");
			else
				printf("0\n");
				
		}else if (str=="toggle"){
			int x;
			cin>>x;
			bool flag=false;
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==x)
				{	flag=true;
					for(int k=j;k<v.size()-1;k++)
						v[k]=v[k+1];
					v.pop_back();
				}
			}
			if(!flag)
				v.push_back(x);
			
		}else if (str=="all"){
			
			while(v.size()!=0)
				v.pop_back();
			for(int j=1;j<=20;j++)
				v.push_back(j);
				
		}else if (str=="empty")
		{
			while(v.size()!=0)
				v.pop_back();
		}
		
	}	



	return 0;
}

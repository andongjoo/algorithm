#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int tc,ans;
int n,k;
vector<string> v;
bool cmp(char a,char b)
{
	return a>b;
}

int htod(string str,int l)
{
	int temp=0;
	int hex=1;
//	cout<<str<<"\n";
	for(int i=l-1;i>=0;i--)
	{
		int x;
		if(str[i]=='A')
		{
			x=10;
		}else if (str[i]=='B')
		{
			x=11;
		}else if (str[i]=='C')
		{
			x=12;
		}else if (str[i]=='D')
		{
			x=13;
		}else if (str[i]=='E')
		{
			x=14;
		}else if (str[i]=='F')
		{
			x=15;
		}else{
			x=str[i]-'0';
		}
//		printf("x:%d\n",x);
		temp+=(x*hex);
		hex*=16;
	}
	
	return temp;
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
//	ios::sync_with_stdio(false);
	
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		v.clear();
//		cin>>n;
		cin>>n>>k;
		string s;
		cin>>s;
		int l=n/4;
		int p=0;
		for(int i=0;i<n/4;i++)
		{
			string tmp;
			for(int j=0;j<4;j++)	
			{
				bool flag=true;
				tmp=s.substr(j*l,l);
				for(int z=0;z<v.size();z++)
				{
					if(v[z]==tmp)
					{
						flag=false;
					}
				}
				if(flag)
					v.push_back(tmp);
				p+=l;
			}
			s=s.substr(s.length()-1,1)+s.substr(0,s.length()-1);
//			cout<<s<<"\n";
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
//		for(int i=0;i<v.size();i++)
//			printf("s:%d\n",htod(v[i],n/4));
		
		
		ans=htod(v[k-1],n/4);
		printf("#%d %d\n",t,ans);
	}

	
	
	return 0;
}

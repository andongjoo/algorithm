#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX=15+1;
char a[MAX];

int l,c;
vector<string> s;
void dfs(int index,int cnt,vector<char> &v)
{
	if(index>c)
	{
		return;
	}
	if(cnt==l)
	{
		int za=0,mo=0;
		string str="";
		for(int i=0;i<l;i++)
		{
			if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u' )
				mo++;
			else
				za++;
			
			str+=v[i];
		
		}
		
		if(za>=2 && mo>=1)
		{
			
//		cout<<za<<" "<<mo<<"\n";
//		cout<<str<<"\n";
			
			s.push_back(str);
					
		}
		
//		printf("za: %d mo %d \n",za,mo);
//		cout<<str<<"\n";
		
		return;
	}
	
	dfs(index+1,cnt,v);
	v.push_back(a[index]);
	dfs(index+1,cnt+1,v);
	v.pop_back();
}

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>l>>c;
	for(int i=0;i<c;i++)
		cin>>a[i];
	sort(a,a+c);
	vector<char> v;
	dfs(0,0,v);
	
	
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<"\n";
//		
	return 0;
}

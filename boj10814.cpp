#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct p{
	int a;
	string s;
	int index;
};

bool cmp(p p1,p p2)
{
	if(p1.a==p2.a)
	{
		return p1.index<p2.index;
	}else
		return p1.a<p2.a;
}

int n;
int main(int argc, char** argv) {
	
	
	cin>>n;
	vector<p> v;
	for(int i=0;i<n;i++)
	{
		int a;
		string s;
		cin>>a>>s;
		p px;
		px.a=a;
		px.s=s;
		px.index=i;
		v.push_back(px);
	}
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0;i<n;i++)
	{
		cout<<v[i].a<<" "<<v[i].s<<"\n";
	}
	return 0;
}

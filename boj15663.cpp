#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int a[10];
vector<int> v;
bool visit[10];

void go(int index,int cnt)
{
	if(cnt==m)
	{
		for(int i=0;i<m;i++)
		{
			printf("%d ",v[i]);
		}printf("\n");
		return;
	}
	int temp=false;
	for(int i=0;i<n;i++)
	{
	
		if(!visit[i] &&temp!=a[i])
		{
			visit[i]=true;
			temp=a[i];
			v.push_back(a[i]);
			go(i,cnt+1);
			v.pop_back();
			visit[i]=false;
		}
	}
}


int main(int argc, char** argv) {
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	sort(a,a+n);
	go(0,0);
	return 0;
}

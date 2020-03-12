#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[10001];
int a[10];
int n,m;
vector<int> v,v2;
void go(int index,int cnt)
{
	if(cnt==m)
	{
		for(int i=0;i<v.size();i++)
		{
			printf("%d ",v[i]);
		}
		printf("\n");
		return;
	}
	if(index==n)
	{
		return;
	}
	
	for(int i=index;i<v2.size();i++)
	{
//		if(!visit[i])
//		{
//			visit[i]=true;
			v.push_back(v2[i]);
			go(i,cnt+1);
			v.pop_back();
//			visit[i]=false;
//		}
	}
	
}

int main(int argc, char** argv) {

	cin>>n>>m;
	v.clear();
	v2.clear();
	for(int i=0;i<10001;i++)
		visit[i]=false;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		visit[a[i]]=1;
	}
	for(int i=0;i<10001;i++)
	{
		if(visit[i])
		{
			v2.push_back(i);
			
		}
	}
//	for(int i=0;i<v2.size();i++)
//		printf("%d ",v2[i]);
//	printf("\n");
//	printf("%d",v2.size());
	sort(v2.begin(),v2.end());
	go(0,0);
	
	return 0;
}

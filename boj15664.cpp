#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[10001];
bool visit2[10001];
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
	int temp=false;
	
	printf("temp:%d\n",temp);
	for(int i=index;i<n;i++)
	{
		
		if(!visit[i] && temp!=a[i])
		{
				temp=a[i];
				visit[i]=true;
				v.push_back(a[i]);
				go(i+1,cnt+1);
				v.pop_back();
				visit[i]=false;
				
		}
	}
	
}

int main(int argc, char** argv) {

	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	go(0,0);
	
	return 0;
}

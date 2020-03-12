#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
bool visit[10];
int a[10];
int n,m;
void per(int index,int cnt)
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
	
	for(int i=0;i<n;i++)
	{
		
			v.push_back(a[i]);
			per(index+1,cnt+1);
			v.pop_back();
		
	}
}


int main(int argc, char** argv) {
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	per(0,0);
	return 0;
}

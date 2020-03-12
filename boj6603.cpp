#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX=50;
int a[MAX];
bool visit[MAX];
int n;
void dfs(int index,int cnt)
{
	
	if(cnt==6)
	{
		for(int i=0;i<n;i++)
		{
				if(visit[i])
				printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	
	
	if(n-index<6-cnt)
	{
		return;
	}	

	visit[index]=1;
	dfs(index+1,cnt+1);
	visit[index]=0;
	dfs(index+1,cnt);
	
}

int main(int argc, char** argv) {
	while(1)
	{
		
		cin>>n;
		if(n==0)
			break;
		
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		dfs(0,0);
		printf("\n");
	}
	
	return 0;
}

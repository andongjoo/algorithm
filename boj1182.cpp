#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1000001;
int a[MAX];
bool visit[MAX];
int n,s;
int ans;
void dfs(int index,int cnt)
{
	if(index>=n )
	{
		if(cnt>0)
		{
			
			int sum=0;
			for(int i=0;i<n;i++)
			{
					if(visit[i])
					{	
//						printf("%d ",a[i]);
						sum+=a[i];
					}
			}
//			printf("sum:%d \n",sum);
			if(sum==s)
				ans++;
		}
		return;
	}
	
	if(!visit[index])
	{
		visit[index]=1;
		dfs(index+1,cnt+1);
		visit[index]=0;
	}
	dfs(index+1,cnt);
	
}

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>n>>s;
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	dfs(0,0);
	printf("%d",ans);
	return 0;
}

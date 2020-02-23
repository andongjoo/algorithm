#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX=21;
int a[MAX][MAX]={0};
int n;
int check[MAX];
int ans=987654321;

void get_sum();

void go(int index,int cnt)
{
	
	if(cnt==n/2 && index==n)
	{
		get_sum();
		return;
	}
	
	if(index==n)
		return;
	
	check[index]=1;
	go(index+1,cnt+1);
	check[index]=0;
	go(index+1,cnt);
	
}

void get_sum()
{
	int start_sum=0;
	int link_sum=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(check[i] && check[j]==1)
			{
				start_sum+=a[i][j];
				start_sum+=a[j][i];
			}
			else if (!check[i] && !check[j])
			{
				link_sum+=a[i][j];
				link_sum+=a[j][i];
			}
		}
	}
	
	int x=abs(start_sum-link_sum);
	ans=min(ans,x);	
}


int main(int argc, char** argv) {
	cin>>n;
	
	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}	
	go(0,0);
	printf("%d",ans);
	
	
	return 0;
}

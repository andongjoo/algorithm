#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
const int MAX=101;
int card[MAX]={0};
int ans=0;
int check[MAX]={0};

int main(int argc, char** argv) {

	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>card[i];
	}
	
	for(int i=0;i<n;i++)
	{
		check[i]=1;
		for(int j=1;j<n;j++)
		{
			if(check[j]==0)
			{
			check[j]=1;
			for(int k=0;k<n;k++)
			{
				if(check[k]==0)
				{
					check[k]=1;
					if(card[i]+card[j]+card[k]<=m)	
						ans=max(ans,card[i]+card[j]+card[k]);
					check[k]=0;
				}
			}
			check[j]=0;
			}
		}
		check[i]=0;
	}
	printf("%d\n",ans);
	
	return 0;
}

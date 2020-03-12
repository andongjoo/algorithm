#include <iostream>
#include<algorithm>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int n,m;
int ans=1999999999;
vector<int> v;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		v.push_back(num);
	}
	
	
	int s=0;
	int e=0;
//	for(int i=0;i<n;i++)
//	{
//		printf("%d ",dp[i]);
//	}printf("\n");
//	
	int sum=v[0];
	
	while(s<=e &&e<n)
	{
//		printf("%d\n",s);
		
		if(sum<m)
		{
				sum+=v[++e];
		}
		else if (sum==m)
		{
			ans=min(ans,e-s+1);
			sum+=v[++e];
		}else if (sum>m)
		{
			ans=min(ans,e-s+1);
			sum-=v[s++];
		}
	}
	
	if(ans==1999999999)
		printf("0");
	else
		printf("%d",ans);
	
	
	return 0;
}

#include <iostream>
#include<algorithm>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int n,m;
int ans;
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
	
	for(int i=0;i<n;i++)
	{
		int sum=0;
		
		for(int j=i;j<n;j++)
		{
			sum+=v[j];
			if(sum==m)
			{
				ans++;
				break;
			}	
			
			if(m<sum)
				break;
		}
		
	}
	
	printf("%d",ans);
	
	return 0;
}

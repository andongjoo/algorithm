#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=4000;
int n;
int a[4][MAX];
int ab[MAX*MAX];
int cd[MAX*MAX];
long long ans;


int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>a[j][i];
		}
	}	

	int index=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ab[index]=a[0][i]+a[1][j];
			cd[index]=a[2][i]+a[3][j];
			index++;
		}
	}
	sort(ab,ab+index);
	sort(cd,cd+index);
	
	int ab_idx=0;
	int cd_idx=index-1;
	
	
	while(ab_idx<index && cd_idx>=0)
	{
		
		if(ab[ab_idx] + cd[cd_idx]==0)
		{
			int flag=ab_idx;
			long long same_ab=0,same_cd=0;
			while(ab[ab_idx]+cd[cd_idx]==0)
			{
				if(ab_idx>=index)
					break;
				same_ab++;
				ab_idx++;
			}
			
			while(ab[flag]+cd[cd_idx]==0)
			{
				if(cd_idx<0)
					break;
				same_cd++;
				cd_idx--;
			}
			
			ans+=(same_cd*same_ab);
			
		}else if (ab[ab_idx]+cd[cd_idx] <0)
			ab_idx++;
		else
			cd_idx--;
		
		
		
		
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}

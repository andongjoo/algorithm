#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=12;

int a[MAX];
int op[4];
int ans;
int n,tc,min_num,max_num;
vector<int> v;

void calc()
{
	int sum=a[0];
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==0)
		{
			sum+=a[i+1];
		}else if(v[i]==1)
		{
			sum-=a[i+1];
		}else if (v[i]==2)
		{
			sum*=a[i+1];
		}else if (v[i]==3)
		{
			sum/=a[i+1];
		}
	}
	
	max_num=max(max_num,sum);
	min_num=min(min_num,sum);
	printf("%d\n",sum);
}


void dfs(int index)
{
//	printf("%d %d %d\n",index,sum);
	
	if(index==n-1)
	{
			
			calc();
//			printf("%d\n",sum);
//			max_num=max(max_num,sum);
//			min_num=min(min_num,sum);
			
			return;
	}
	
	for(int i=0;i<4;i++)
	{
		if(op[i]<=0)
			continue;
		
		op[i]--;
		v.push_back(i);
		dfs(index+1);
		op[i]++;
		v.pop_back();
		
	}	

}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		v.clear();
		for(int i=0;i<4;i++)
		{
			op[i]=0;
		}
		max_num=-987987987;
		min_num=987987987;
		
		cin>>n;
		for(int i=0;i<4;i++)
		{
			cin>>op[i];
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		dfs(0);
		ans=max_num-min_num;
	
		printf("#%d %d\n",t,ans);
	}


	return 0;
}

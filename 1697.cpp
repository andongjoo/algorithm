#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX=100001;
int n,k;
int check[MAX]={0};
int cnt[MAX]={0};
queue<int> q;
int ans=99999999;

int main(int argc, char** argv) {

	cin>>n>>k;
	
	q.push(n);
	check[n]=1;
	while(!q.empty())
	{
	
		int x= q.front();
		q.pop();
		if(x == k)
		{
			ans=min(cnt[x],ans);
			break;
		}	
		
		if(x+1<MAX && check[x+1]==0)
		{
				check[x+1]=1;
				q.push(x+1);
				cnt[x+1]=cnt[x]+1;
		}
		if(x>0 && check[x-1]==0)
		{		q.push(x-1);
			check[x-1]=1;
			cnt[x-1]=cnt[x]+1;
		}
		
		if(x*2<MAX && check[x*2]==0)
		{	q.push(2*x);
			check[x*2]=1;
			cnt[x*2]=cnt[x]+1;
		}
		
	}

	printf("%d\n",ans);

	return 0;
}

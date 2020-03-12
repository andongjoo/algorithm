#include <iostream>
#include <deque>
using namespace std;
int cnt[100001];
int n,m;
bool visit[100001];
deque<int> dq;
int ans=987987987;
int main(int argc, char** argv) {
	cin>>n>>m;
	
	dq.push_back(n);
	cnt[n]=0;
	visit[n]=0;
	while(!dq.empty())
	{
		int cur=dq.front();
		dq.pop_front();
		
		
		if(cur==m)
		{
			printf("%d",cnt[cur]);
			return 0;
		}
		if(cur!=0 && cur*2<=100000)
		{
			if(!visit[cur*2])
			{
				visit[cur*2]=true;
				dq.push_front(cur*2);
				cnt[cur*2]=cnt[cur];
			}
		}
		
	
		if(cur-1>=0)
		{
			if(!visit[cur-1])
			{
				visit[cur-1]=true;
				dq.push_back(cur-1);
				cnt[cur-1]=cnt[cur]+1;
			}
		}
		
		if(cur+1<=100000)
		{
			if(!visit[cur+1])
			{
				visit[cur+1]=true;
				dq.push_back(cur+1);
				cnt[cur+1]=cnt[cur]+1;
			}
		}
		
		
	}
	
	return 0;
}

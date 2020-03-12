#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX=1000000+1;
int f,s,g,u,d;
int cnt;
int visit[MAX];

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	cin>>f>>s>>g>>u>>d;
	
	queue<int> q;
	q.push(s);
	q.push(0);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		int cnt=q.front();
		q.pop();
		
		if(cur==g)
		{
			printf("%d",cnt);
			return 0;
		}
		if(cur+u<=f && !visit[cur+u])
		{
			
			visit[cur+u]=1;
			q.push(cur+u);
			q.push(cnt+1);
		}
		
		if(cur-d>=1  && !visit[cur-d])
		{
			visit[cur-d]=1;
			q.push(cur-d);
			q.push(cnt+1);
		}
		
	}
	printf("use the stairs");

	return 0;
}

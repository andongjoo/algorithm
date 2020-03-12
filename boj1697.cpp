#include <iostream>
#include <queue>
int n,k;
bool check[100000+1];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	cin>>n>>k;
	
	queue<int> q;
	q.push(n);
	q.push(0);
	int ans=0;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		int time=q.front();
		q.pop();
		
//		printf("%d %d\n",cur,time);
		if(cur==k)
		{
			printf("%d",time);
			return 0;
		}
		
		if(cur-1>=0 && !check[cur-1])
		{
				q.push(cur-1);
				q.push(time+1);
				check[cur-1]=1;
		}
		if(cur+1<=100000 && !check[cur+1])
		{
				q.push(cur+1);
				q.push(time+1);
				check[cur+1]=1;
		}
		if(cur*2<=100000 && !check[cur*2])
		{
				q.push(cur*2);
				q.push(time+1);
				check[cur*2]=1;
		}
		
	}
	
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	queue<int> q;
	
	int n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		q.push(i);
	}
	printf("<");
	while(!q.empty())
	{	int t=k-1;
		while(t--)
		{
			int item=q.front();
			q.pop();
			q.push(item);
			
		}
		
		if(q.size()==1)
		{
			printf("%d>\n",q.front());
		}else
		{
		
			printf("%d, ",q.front());
			
		}
		q.pop();
	}
	return 0;
}

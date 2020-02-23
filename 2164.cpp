#include <iostream>
#include <queue>
using namespace std;



int main(int argc, char** argv) {
	int n;
	cin>>n;
	queue<int> q;
	
	
	for(int i=1;i<=n;i++)
	{
		q.push(i);
	}


	while(1)
	{
		if(q.size()==1)
		{
			printf("%d\n",q.front());
			break;
		}
		q.pop();
		
		int item=q.front();
		q.pop();
		q.push(item);
		
		
	}

	return 0;
}

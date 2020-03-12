#include <iostream>
#include <deque>
#include <string>
using namespace std;


int main(int argc, char** argv) {
	deque<int> dq;
	int n;
	cin>>n;
	int num;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s=="push_back")
		{
			cin>>num;
			dq.push_back(num);
		}else if (s=="push_front")
		{
			cin>>num;
			dq.push_front(num);
		}else if (s=="front")
		{
			if(dq.empty())
				printf("-1\n");
			else
				printf("%d\n",dq.front());
			
		}else if (s=="back")
		{
			if(dq.empty())
				printf("-1\n");
			else
				printf("%d\n",dq.back());
			
		}else if (s=="size")
		{
			printf("%d\n",dq.size());
		}else if (s=="empty")
		{
			printf("%d\n",dq.empty());
			
		}else if (s=="pop_front")
		{
			if(dq.empty())
				printf("-1\n");
			else
			{
					printf("%d\n",dq.front());
					dq.pop_front();
			}
		}else if (s=="pop_back")
		{
			
			if(dq.empty())
				printf("-1\n");
			else
			{
				printf("%d\n",dq.back());
				dq.pop_back();
			}
		}
		
		
	}
	
	

	return 0;
}

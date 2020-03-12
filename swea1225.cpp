#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int ans;
int tn;
list<int> l;
int main(int argc, char** argv) {

	for(int t=1;t<=10;t++)
	{
		cin>>tn;
		l.clear();
		
		for(int i=0;i<8;i++)
		{
			int n;
			cin>>n;
			l.push_back(n);
		}
		int index=1;
		while(1)
		{
			int temp=l.front();
			if(temp>=index)
				temp-=index;
			else
				temp=0;
				
			index++;
			
			if(index>5)
				index=1;
			
			l.pop_front();
			l.push_back(temp);
			
			if(l.back()==0)
			{
				break;
			}
		}
		
		printf("#%d ",t);
		for(int i=0;i<8;i++)
		{
			printf("%d ",l.front());
			l.pop_front();
		}
		printf("\n");
	}
	return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	stack<int> s;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		if(str=="push"){
			int n;
			cin>>n;
			s.push(n);
		}else if (str=="top"){
			if(s.empty())
				printf("-1\n");
			else
				printf("%d\n",s.top());
		}else if(str=="size")
		{
			printf("%d\n",s.size());
		}else if (str=="empty"){
			if(s.empty())
				printf("1\n");
			else
				printf("0\n");
		}else if (str=="pop"){
			if(s.empty())
			{printf("-1\n");
			}else{
				int num=s.top();
				printf("%d\n",num);
				s.pop();
			}
		}
	}

	return 0;
}

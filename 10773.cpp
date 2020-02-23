#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char** argv) {
	stack<int> s;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int item;
		cin>>item;
		if(item==0)
			s.pop();
		else
			s.push(item);
	}
	int ans=0;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		ans+=s.top();
		s.pop();
			
	}
	printf("%d",ans);
	
	return 0;
}

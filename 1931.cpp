#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX=100001;
int n;
typedef struct t_len{
	int start;
	int end;
};

bool cmp(t_len t1,t_len t2)
{
	if(t1.end==t2.end)
		return t1.start<t2.start;
	else 
		return t1.end<t2.end;	
}

int main(int argc, char** argv) {

	cin>>n;
	t_len t[MAX];
	int cur=0;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>t[i].start>>t[i].end;
		
	}
	
	
	sort(t,t+n,cmp);
	
	for(int i=0;i<n;i++)
	{
		if(t[i].start>=cur)
		{
			cnt++;
			cur=t[i].end;
		}
	}
	printf("%d",cnt);

	return 0;
}

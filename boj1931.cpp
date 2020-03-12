#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=100000+1;


struct meeting{
	int start;
	int end;
};
meeting a[MAX];
bool cmp(meeting t1,meeting t2)
{
	if(t1.end==t2.end)
		return t1.start<t2.start;
	else
		return t1.end<t2.end;
}
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int s,e;
		cin>>s>>e;
		a[i].start=s;
		a[i].end=e;
	}
	int cur=0;
	int cnt=0;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(a[i].start>=cur)
		{
			cnt++;
			cur=a[i].end;
		}
	}
	
	printf("%d",cnt);
	
	return 0;
}

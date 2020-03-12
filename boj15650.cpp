#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
bool visit[10];
int n,m;
void per(int index,int cnt)
{
	if(cnt==m)
	{
		for(int i=0;i<v.size();i++)
		{
			printf("%d ",v[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=index;i<=n;i++)
	{
			v.push_back(i);
			per(i+1,cnt+1);
			v.pop_back();
		
	}
}


int main(int argc, char** argv) {
	
	cin>>n>>m;
	per(1,0);
	return 0;
}

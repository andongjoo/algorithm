#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX=101;
int n,m;
bool visit[MAX];
vector<int> v;
void go(int index,int cnt)
{
	if(cnt==m){
		for(int i=0;i<v.size();i++)
			printf("%d ",v[i]);
		printf("\n");
		return;
	}
	
	if(index==n)
		return;
	
	for(int i=0;i<n;i++)
	{
		if(!visit[i])
		{
			v.push_back(i+1);
			visit[i]=true;
			go(index+1,cnt+1);
			visit[i]=false;
			v.pop_back();
		}
	}
}

int main(int argc, char** argv) {
	
	cin>>n>>m;
	
	go(0,0);
	
}

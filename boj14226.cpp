#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;

const int MAX=2001;
int cnt[MAX][MAX];
typedef	struct{
	int x;
	int y;
}data;

queue <data> q;


int main(int argc, char** argv) {
	cin>>n;
	
	q.push({1,0});
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		q.pop();		
//		printf("emoticon: %d clip: %d time:%d\n",x,y,cnt[x][y]);
		if(x==n)
		{
			printf("%d\n",cnt[x][y]);
			return 0;
		}
		int nx[]={x,x+y,x-1};
		int ny[]={x,y,y};
		for(int i=0;i<3;i++){
			
			if(nx[i]<0 || nx[i]>2*n)
				continue;
			if(cnt[nx[i]][ny[i]])
				continue;
			q.push({nx[i],ny[i]});
			cnt[nx[i]][ny[i]]=cnt[x][y]+1;
		}
		
	}	
	return 0;
}

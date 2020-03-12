#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct water{
	int a;
	int b;
	int c;
};
vector<int> ans;

bool check[201][201];
queue<water> q;

int A,C,B;
void sw()
{
	q.push({0,0,C});
	while(!q.empty())
	{
		water cur=q.front();
		q.pop();
		
		if(check[cur.a][cur.b])
			continue;
			
		check[cur.a][cur.b]=true;
		
		//
		if(cur.a==0)
		   ans.push_back(cur.c);
		   
		   
		   
		if(cur.a+cur.b>B)
			q.push({cur.a+cur.b-B,B,cur.c});
		else
			q.push({0,cur.a+cur.b,cur.c});
		
		if(cur.a+cur.c>C)
			q.push({cur.a+cur.c-C,cur.b,C});
		else
			q.push({0,cur.b,cur.a+cur.c});
			
		if(cur.b+cur.c>C)
			q.push({cur.a,cur.b+cur.c-C,C});
		else
			q.push({cur.a,0,cur.b+cur.c});
			
		
		if(cur.c+cur.a>A)
			q.push({A,cur.b,cur.a+cur.c-A});
		else
			q.push({cur.a+cur.c,cur.b,0});
			
		if(cur.b+cur.c>B)
			q.push({cur.a,B,cur.b+cur.c-B});
		else	
			q.push({cur.a,cur.b+cur.c,0});
			
		if(cur.b+cur.a>A)
			q.push({A,cur.a+cur.b-A,cur.c});
		else
			q.push({cur.a+cur.b,0,cur.c});
			
			
		
	}
	
}

int main(int argc, char** argv) {

	cin>>A>>B>>C;
	sw();
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}

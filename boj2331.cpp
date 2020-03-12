#include <iostream>
#include <vector>


#include <string>
#include <stack>
using namespace std;

int n;

vector<int> v[1000000];
vector<string> cnt;
bool visit[1000000];
stack<string> stck;

int pow(int n,int m)
{
	if(m==1)
		return n;
	else 
		return n*pow(n,m-1);
}

void dfs(string node)
{
	stck.push(node);
	visit[stoi(node)]=true;
	int sum=0;
	string temp=node;	
	for(int i=0;i<temp.size();i++)
	{
				int num=temp[i]-'0';
				sum+=pow(num,n);
	}
	
	if(visit[sum])
	{
		while(to_string(sum)!=stck.top())
		{
			stck.pop();
		}
		stck.pop();
	}
	else{
			
		temp=to_string(sum);
		dfs(temp);		
	}
	
}

int main(int argc, char** argv) {
	
	string str;
	cin>>str;
		cin>>n;
	dfs(str);
	
	printf("%d",stck.size());
	return 0;
}

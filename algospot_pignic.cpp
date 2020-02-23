#include <iostream>
#include <string>
using namespace std;

int n,f;
int friends[10][10];
bool taken[10];
int countPairings(bool taken[10])
{
	int firstFree=-1;
	
	for(int i=0;i<n;i++)
	{
		if(!taken[i])
		{
			firstFree=i;
			break;
		}
	}
	
	if(firstFree==-1)
	{
		return 1;
	}
	int ret=0;
	
	for(int pairWith=firstFree+1;pairWith<n;pairWith++)
	{
		if(!taken[pairWith] && friends[firstFree][pairWith])
		{
			taken[firstFree]=taken[pairWith]=true;
			ret+=countPairings(taken);
			taken[firstFree]=taken[pairWith]=false;
		}
		
	}
	return ret;
}

int main(int argc, char** argv) {

	int t;
	cin>>t;
	
	for(int test=0;test<t;test++)
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				friends[i][j]=0;
				
		for(int i=0;i<10;i++)
			taken[i]=0;
			
		cin>>n>>f;
		for(int i=0;i<f;i++)
		{
			int a,b;
			cin>>a>>b;
			friends[a][b]=1;
			friends[b][a]=1;
		}
				
		int answer=countPairings(taken);
		printf("%d\n",answer);
	}
	
	
	return 0;
}

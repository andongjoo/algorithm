#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=8;
int n;
double dist[MAX][MAX];
double shortestPath(vector<int> &path,vector<bool> &visited,double current)
{
	
	if(path.size()==n)
	{
		return current;	
	}
	
	double result=numeric_limits<double>::max();

	for(int i=0;i<n;i++)
	{
		if(visited[i])
			continue;
		int here=path.back();
		path.push_back(i);
		visited[i]=true;
		double candidate=shortestPath(path,visited,current+dist[here][i]);
		result=min(result,candidate);
	
		visited[i]=false;
		path.pop_back();
	}
	
	return result;
}

int main(int argc, char** argv) {
	int test;
	cin>>test;
	double result;
	for(int t=0;t<test;t++)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>dist[i][j];
			}
		}
		
		
        double answer = numeric_limits<double>::max();
		for(int i=0;i<n;i++)
		{
			vector<int> path(1,i);
			vector<bool> visited(n,false);	
			visited[i]=true;
			result=shortestPath(path,visited, 0.000000000);
			if(answer>result)
				answer=result;

		}	
		printf("%.10f\n",answer);	
	}
	
	
	

	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namepace std;
const int MAX=9+1;
int map[MAX][MAX];
int number[MAX];
bool check(int y,int x)
{
	for(int i=1;i<10;i++)
		number[i]=0;
		
	for(int i=y;i<y+3;i++)
	{
		for(int j=x;j<x+3;j++)
		{
			number[map[i][j]]++;
		}
	}
	
	
	for(int i=1;i<10;i++)
		if(number[i]>1)
			return false;
	
	return true;
}


void bfs()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			number[map[i][j]]=1;
		}
	}
	
	
	
	
}



int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>a[i][j];
			
		


	return 0;
}

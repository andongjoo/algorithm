#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX=11;
int n,m;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
char board[MAX][MAX]={0};
int cnt=0;

typedef struct ball{
	int ry,rx,by,bx;
};

int rx,ry,by,bx;

void bfs()
{
	queue<ball> q;
	q.push({rx,ry,by,bx});
	
	while(!q.empty())
	{
		
		int nry=q.front().ry;
		int nrx=q.front().rx;
		int nbx=q.front().bx;
		int nby=q.front().by;
		
		
		
		
		
		
	}
	
}

int main(int argc, char** argv) {

	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		
		cin>>board[i];
	}


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j]=='R')
			{
				rx=i;
				ry=j;
				board[i][j]='.';
			}
			
			if(board[i][j]=='B')
			{
				bx=i;
				by=j;
				board[i][j]='.';
			}
		}
	}
	
	bfs();


	

	return 0;
}

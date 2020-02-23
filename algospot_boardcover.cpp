#include <iostream>
using namespace std;
int board[20][20];
int test,w,h;

const int block[4][3][2]={
	 {{0,0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}

};

bool check(int board[][20],int y,int x,int type,int delta)
{
	bool flag=true;
	for(int i=0;i<3;i++)
	{
		const int ny=y+block[type][i][0];
		const int nx=x+block[type][i][1];
		if(ny<0 || nx<0 || ny>=h|| nx>=w)
			flag=false;
		else if((board[ny][nx]+=delta) > 1)
			flag=false;
	}
	return flag;
}

int cover(int board[][20])
{
	int y=-1,x=-1;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
		
			if(board[i][j]==0)
			{
				y=i;
				x=j;
				break;
			}		
		}
		if(y!=-1)
			break;
	}
	
	if(y==-1)
		return 1;
	int ret=0;
	
	for(int i=0;i<4;i++)
	{
		if(check(board,y,x,i,1))
			ret+=cover(board);
		
		check(board,y,x,i,-1);
	}
	
	
	return ret;
	
}


int main(int argc, char** argv) {
	cin>>test;
	
	for(int t=0;t<test;t++)
	{
		cin>>h>>w;
		int white=0;
		for(int i=0;i<h;i++)
		{
				char bw[20];
				cin>>bw;
				for(int j=0;j<w;j++)
				board[i][j]=  (bw[j]=='#') ? 1:0;
		}
		
//		for(int i=0;i<h;i++)
//		{
//			for(int j=0;j<w;j++)
//			{
//				printf("%d ",board[i][j]);
//			}printf("\n");
//		}
		
		int answer=cover(board);
		printf("%d\n",answer);	
	}
	
	return 0;
}

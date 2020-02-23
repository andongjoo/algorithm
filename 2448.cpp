#include <iostream>
using namespace std;
const int MAX=10000;
char arr[MAX][MAX];

void printstar(int y,int x)
{
	arr[y][x]='*';
	arr[y+1][x+1]='*';
	arr[y+1][x-1]='*';
	arr[y+1][x]=' ';
	arr[y+2][x-2]='*';
	arr[y+2][x-1]='*';
	arr[y+2][x]='*';
	arr[y+2][x+1]='*';
	arr[y+2][x+2]='*';
	
}

void star(int n,int y,int x)
{
	if(n==3)
	{
		printstar(y,x);
		return;
	}		
	n/=2;
	
	star(n,y,x);
	star(n,y+n,x-n);
	star(n,y+n,x+n);
	
}
int main(int argc, char** argv) {
	int k;
	cin>>k;
	star(k,0,k);
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<k*2;j++)
		{
			if(arr[i][j]=='*')
				printf("%c",arr[i][j]);
			else
				printf(" ");
		}printf("\n");
	}
	return 0;
}

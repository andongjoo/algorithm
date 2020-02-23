#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=10000;
char arr[MAX][MAX];


void printstar(int y,int x)
{
	arr[y][x]='*';
	arr[y][x+1]='*';
	arr[y][x+2]='*';
	arr[y+1][x]='*';
	arr[y+1][x+1]=' ';
	arr[y+1][x+2]='*';
	arr[y+2][x]='*';
	arr[y+2][x+1]='*';
	arr[y+2][x+2]='*';
}


void star(int num,int y,int x)
{
	if(num==3)
	{
		printstar(y,x);
		return ;
	}
	num/=3;
	star(num,y,x);
	star(num,y+num,x);
	star(num,y+num*2,x);
	star(num,y,x+num);
	star(num,y,x+num*2);
	star(num,y+num,x+num*2);
	star(num,y+num*2,x+num);
	star(num,y+num*2,x+num*2);
}

int main(int argc, char** argv) {


	int n;
	cin>>n;
	star(n,0,0);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]=='*')
			printf("%c",arr[i][j]);
			else
				printf(" ");
		}printf("\n");
	}
	return 0;
}

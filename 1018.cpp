#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m;
char a[51][51];

string w[8] = {
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" }
};

string b[8] = {
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" }
};

int get_b(int r,int c)
{
	int count=0;
	for(int i=r;i<r+8;i++)
	{
		for(int j=c;j<c+8;j++)
		{
			if(a[i][j]!=b[i-r][j-c])
				count++;	
			
		}
	}
	
	return count;
}


int get_w(int r,int c)
{
	int count=0;
	for(int i=r;i<r+8;i++)
	{
		for(int j=c;j<c+8;j++)
		{
			if(a[i][j]!=w[i-r][j-c])
				count++;	
			
		}
	}
	
	return count;
}
int main(int argc, char** argv) {
	cin>>n>>m;
	int ans=999999999;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			if(i>=0 && j>=0 && i+7<n&&j+7<m)
			{
				ans=min(ans,min(get_b(i,j),get_w(i,j)));
			}
		}
	}
	printf("%d",ans);



	return 0;
}

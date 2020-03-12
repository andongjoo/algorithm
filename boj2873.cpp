#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAX=1001;
int r,c;

int a[MAX][MAX];


int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int my,mx;
	cin>>r>>c;
	string s="";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}


	if(r%2==1)
	{
		int cnt=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c-1;j++)
			{
				if(i%2==0)
					s+="R";
				else
					s+="L";
			}
			if(i !=R-1)
				s+="D";
		}
		
		
	}else if (r%2==0 && c%2==1)
	{
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r-1;j++)
			{
				if(i%2==0)
					s+="D";
				else
					s+="U";
			}
			if(i!=c-1)
				s+='R';
		}
		
		
	}else if( r%2==0 && c%2==0)
	{
		
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r-1;j++)
			{
				
				if( (i+j)%2==1 && score>a[i][j])
				{
					score=a[i][j];
					my=i;
					mx=j;
				}
			}
			
		}
		
		
		
		
	}

	return 0;
}

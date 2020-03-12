#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

bool p(char str[],int start,int end)
{
	
	if(start==end)
		return true;
	else if(start+1==end)
		return false;
	else{
		if(str[start]==str[end])
			return p(str,start+1,end-1);
		else
			return false;
	}
} 
char str[8][8];
int N;
int main(int argc, char** argv) {
	
	for(int tc=1;tc<=10;tc++)
	{
		cin>>N;	
		int answer=0;	
		for (int i = 0; i < 8; i++)

		{

			for (int j = 0; j < 8; j++)

			{

			cin>> str[i][j];

			}

		}
		
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(j+N-1<8 && str[i][j]==str[i][j+N-1])
				{
					for(int k=1;k<N-1;k++)
					{
						if(str[i][j+k]!=str[i][j+N-1-k])
							break;
					
						if ( k ==N-2)
							answer++;	
					}
				
				
				}	
				
				if(i+N-1<8 && str[i][j]==str[i+N-1][j])
				{
					for(int k=1;k<N-1;k++)
					{
						if(str[i+k][j]!=str[i+N-1-k][j])
							break;
					
						if ( k ==N-2)
							answer++;	
					}
				
				
				}
			} 
		}		
		
		printf("#%d %d\n",tc,answer);
	}
	
	return 0;
}

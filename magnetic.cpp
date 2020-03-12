#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	for(int t=0;t<10;t++)
	{
		int map[100][100];
		int n;
		cin>>n;
		int answer=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>map[i][j];
		}
		
		for(int i=0;i<n;i++)
		{
				int index1=0,index2=0;
				for(int k=0;k<n;k++)
				{
					if(map[k][i]==1)
					{
						index1=k;
						break;
					}
				}
				
				for(int k=n-1;k>=0;k--)
				{
					if(map[k][i]==2)
					{
						index2=k;
						break;
					}
				}
			if (index1>index2)
				continue;
			int flag=1;
			int cnt=0;	
			for(int j=index1;j<=index2;j++)
			{
				if(map[j][i]==1)	
				{
					flag=map[j][i];
				}else if(map[j][i]==2 && flag!=map[j][i])
				{
					flag=map[j][i];
					cnt++;
				}
				
			}
			answer+=cnt;
		}
		
		
		printf("#%d %d\n",t+1,answer);
	}
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=100;
int a[MAX][MAX];
int temp;
int ans;
int t;
void init()
{
	temp=99999999;
	ans=-1;
}
void input()
{
	cin>>t;
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			cin>>a[i][j];
}

int dfs(int line)
{
	int y=0;
	int x=line;
	int cnt=1;
	int dir=1;
	
	while(1)
	{
	
		if(dir==1)
		{
			y++;
			cnt++;
			while(1)
			{
				if(y==MAX-1)
				{
					return cnt;
				}
				
				if(x+1<MAX)
				{
					if(a[y][x+1]==1)
					{
						dir=2;
						break;
					}
				}
				if(x-1>=0)
				{
					if(a[y][x-1]==1)
					{
						dir=3;
						break;
					}
				}
				y++;
				cnt++;
			}
		
		
		}	
		
		
		else if (dir==2)
		{
			x++;
			cnt++;
			while(1)
			{
				if(y+1<MAX)
				{
					if(a[y+1][x]==1)
					{
						dir=1;
						break;
					}
				}
				x++;
				cnt++;
			}
		}
		else if (dir==3)
		{
			x--;
			cnt++;
			while(1)
			{
				if(y+1<MAX)
				{
					if(a[y+1][x]==1)
					{
						dir=1;
						break;
					}
				}
				x--;
				cnt++;
			}
			
		}
	
}
	
	
}

void solution()
{
	for(int i=0;i<MAX;i++)
		{
			if(a[0][i]==1)
			{
				int c=dfs(i);
				if(temp>c)
				{
					temp=c;
					ans=i;
				}
			
			}
		}
}


void solve()
{
	int tc=10;
	for(int k=1;k<=tc;k++)
	{
		init();
		input();
		solution();
		printf("#%d %d\n",k,ans);
	}
}

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	solve();

	
	return 0;
}

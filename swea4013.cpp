#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tc,k;
int ans;
int a[5][9];

void rotate(int num,int dir) {
    if (dir == 1) {
        int tmp = a[num][8];
        for (int i = 8; i > 1; i--) {
            a[num][i] = a[num][i - 1];
        }
        a[num][1] = tmp;
    }
    else {
        int tmp = a[num][1];
        for (int i = 2; i < 9; i++) {
            a[num][i-1] = a[num][i];
        }
        a[num][8] = tmp;
    }
}

bool c1,c2,c3;

void check(){
	if(a[1][3]!=a[2][7])
		c1=true;
	if(a[2][3]!=a[3][7])
		c2=true;
	if(a[3][3]!=a[4][7])
		c3=true;
}

void init()
{
	c1=false;
	c2=false;
	c3=false;
}
int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		cin>>k;
		c1=false,c2=false,c3=false;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=8;j++)
			{
				
				cin>>a[i][j];
			}
		}
		
//		for(int i=1;i<=1;i++)
//		{
//			for(int j=1;j<=8;j++)
//				printf("%d ",a[i][j]);
//			printf("\n");
//		}
		for(int i=0;i<k;i++)
		{
			init();
			int n,d;
			cin>>n>>d;
			check();
			if(n==1)
			{
				rotate(1,d);
				if(c1)
				{
					rotate(2,d*-1);
					if(c2)
					{
						rotate(3,d);
						if(c3)
						{
							rotate(4,d*-1);
						}
					}
					
				}
			}else if(n==2)
			{
				rotate(2,d);
				if(c1)
				{
					rotate(1,d*-1);
				}
				if(c2)
				{
					rotate(3,d*-1);
					if(c3)
					{
						rotate(4,d);
					}
				}
			}
			else if (n==3)
			{
				rotate(3,d);
				if(c2)
				{
					rotate(2,d*-1);
					if(c1)
					{
						rotate(1,d);
					}
				}
				if(c3)
				{
					rotate(4,d*-1);
				}
			}
			else if(n==4)
			{
				rotate(4,d);
				if(c3)
				{
					rotate(3,d*-1);
					if(c2)
					{
						rotate(2,d);
						if(c1)
						{
							rotate(1,d*-1);
						}
					}
				}
			}
		}
		
		
		
		ans=0;
	
		
		for(int i=1;i<=1;i++)
		{
			for(int j=1;j<=8;j++)
			{
				printf("%d ",a[i][j]);
			}printf("\n");
			
		}
		
//			for (int i = 1; i <= 4; i++) 
//		{
//        	if (a[i][1]) 
//			{
//            	ans += pow(2, i-1);
//        	}
//    	}
		if(a[1][1]==1)
		{
			ans+=1;
		}
		if(a[2][1]==1)
		{
			ans+=2;
		}
		if(a[3][1]==1)
		{
			ans+=4;
		}
		if(a[4][1]==1)
		{
			ans+=8;
		}
		

		printf("#%d %d\n",t,ans);	
	}	
	
	return 0;
}





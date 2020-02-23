#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int answer;
char a[4][8];
int check[4];
void input(int num,int dir){
	if(num==1)
		{
			if(a[0][2]!=a[1][6]){
				
					if(a[1][2]!=a[2][6]){
						
						if(a[2][2]!=a[3][6]){
							
							check[0]=dir;
							check[1]=-1*dir;
							check[2]=dir;
							check[3]=-1*dir;
						}else{
							
							check[0]=dir;
							check[1]=-1*dir;
							check[2]=dir;
						}
					}
					else
						{
							check[0]=dir;
							check[1]=-1*dir;
						}
				}
			else{
				
				check[0]=dir;		
			}
				
		}
		else if(num==2) {
			
			if(a[0][2]!=a[1][6] && a[1][2]!=a[2][6]){
				
				if(a[2][2]!=a[3][6]){
					
							check[0]=-1*dir;
							check[1]=dir;
							check[2]=-1*dir;
							check[3]=dir;
				}else{
							check[0]=-1*dir;
							check[1]=dir;
							check[2]=-1*dir;
				}
				
				
			}else if(a[0][2]!=a[1][6] && a[1][2]==a[2][6])
			{
				check[0]=dir*-1;
				check[1]=dir;
			}else if (a[0][2]==a[1][6] && a[1][2]!=a[2][6])
			{
				
				if(a[2][2]!=a[3][6])
				{
					check[1]=dir;
					check[2]=dir*-1;
					check[3]=dir;	
				}
				else
				{
					check[1]=dir;
					check[2]=dir*-1;
				}
			} 
			
		}
		else if(num==3){
			
			if(a[2][2]!=a[3][6] && a[2][6]!=a[1][2] )
			{
				if(a[0][2]!=a[1][6]){
							check[0]=dir;
							check[1]=dir*-1;
							check[2]=dir;
							check[3]=dir*-1;
							
				}else{
					
					check[1]=dir*-1;
					check[2]=dir;
					check[3]=dir*-1;
				}
			}
			else if (a[2][6]!=a[1][2] && a[2][2]==a[3][6]){
				
				
				if(a[0][2]!=a[1][6])
				{
					
				check[2]=dir;
				check[1]=dir*-1;
				check[0]=dir;
				}
				else{
				
					check[2]=dir;
					check[1]=dir*-1;
				}
			}else if (a[2][6]==a[1][2] && a[2][2]!=a[3][6]){
				
				check[2]=dir;
				check[3]=dir*-1;
				
			}else{
				check[2]=dir;
			}
		}else if (num==4){
			
			
			if(a[3][6]!=a[2][2]){
				
				if(a[1][2]!=a[2][6]){
					
					if(a[0][2]!=a[1][6]){
						
					check[3]=dir;
					check[2]=dir*-1;
					check[1]=dir;
					check[0]=dir*-1;
						
					}else
					{
						
					check[3]=dir;
					check[2]=dir*-1;
					check[1]=dir;
					}
					
				}
				else{
					check[3]=dir;
					check[2]=dir*-1;
				}
				
				
			}else{
				check[3]=dir;
			}
			
			
			
	}
}

void swap_r(int num){
	

	int temp=a[num][0];
	
	for(int i=1;i<8;i++)
	{
		a[num][i-1]=a[num][i];
	}	
	
	a[num][7]=temp;
	
}

//½Ã°Ô»§ 
void swap_l(int num){
	

	int temp=a[num][7];
	
	for(int i=1;i<8;i++)
	{
		a[num][i]=a[num][i-1];
	}	a[num][0]=temp;
	
}



int main(int argc, char** argv) {
	
	for(int i=0;i<4;i++)
	{
		scanf("%s",&a[i]);
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			a[i][j]-='0';
		}
	}





	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int num,dir;
		cin>>num>>dir;
		
		memset(check,false,sizeof(check));
		input(num,dir);
		
		for(int j=0;j<4;j++)
		{
				if(check[j]==1)
				{
					swap_l(j);
				}
				else if (check[j]==-1)
					swap_r(j);
			
		}
		
		
	}
	int x=1;
	for(int i=0;i<4;i++)
	{
//		printf("%d\n",x);
		if(a[i][0]==1)
			answer+=x;
		x*=2;
	}
	printf("%d",answer);
	return 0;
}

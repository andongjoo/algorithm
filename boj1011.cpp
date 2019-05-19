#include <iostream>
using namespace std;
int dp[40000]={0,};

int sum(int n)
{
  int s=(n*(n+1))/2;
  
  return s;
}

int main() {
	int x,y;
	
	cin>>x>>y;
	
	int l = y-x;
  dp[1]=1;
  dp[2]=2;
 
  for(int i=3;i<40000;i++)
  {
    if (i%2==1)
    {
      dp[i]=sum(i/2+1)+sum(i/2);
    }
    else 
    {
      dp[i]= 2*sum(i/2); 
    }
  }
  
  for(int i=1;i<40000;i++)
  {
     if (l >dp[i] && l<=dp[i+1])
       {
        printf("%d ",i+1);
        return 0;
       }
  }
	
	
	return 0;
}

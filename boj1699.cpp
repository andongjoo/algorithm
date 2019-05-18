#include <iostream>
#include <algorithm>

using namespace std;
const int MAX=100001;
int dp[MAX]={0,};
int n;


int main() {

  cin>>n;
  dp[1]=1;
  for(int i=1;i<=n;i++)
  {
    dp[i]=i;
    
  }
  int index;
  while(index*index<=MAX)
  {
    dp[index*index]=1;  
    index++;
  }
  
  
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j*j<=n;j++)
    {
        if ( i>=j*j)
        {
          if (dp[i]>dp[i-j*j]+1)
            dp[i]=dp[i-j*j]+1;
        }
    }
    
    
  }
  printf("%d",dp[n]);
  
  return 0;
}

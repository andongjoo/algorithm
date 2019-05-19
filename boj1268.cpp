#include <iostream>
using namespace std;


int main(int argc, char** argv) {
  
  int n;
  cin >>n;
  int a[n+1][6];
  int b[n+1]={0,};
  
  
  
  for(int i=1;i<=n;i++)
  { for(int j=1;j<=5;j++)
    { cin >> a[i][j]; }
  }
  for(int i=1;i<=n;i++)
  { 
    
  	int check[n+1]={0,};
    for(int j=1;j<=5;j++)
    { 
        for(int k=1;k<=n;k++)
        {   
            if(a[i][j] == a[k][j] && i!=k && check[k]==0 )
              { 
                check[k]=1;
                b[i]++;
                  
              }
          
        }
      
    }
  }
  int max=0;
  for(int i=1;i<=n;i++)
  {
    if(b[i]>max)
      max=b[i];
  }
  for(int i=1;i<=n;i++)
  {
      if(b[i]==max)
      {
        cout<<i;
        return 0;
      }
  }
   
    
      
	return 0;
}

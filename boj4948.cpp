#include <iostream>
#include <math.h>
using namespace std;

int main() {
	
	while(1)
	{
	  int x;
	  cin>>x;
	  
	  if (x==0)
	    break;
	    
	  int cnt=0;

	for(int i=x+1;i<=2*x;i++)
	  {   
	      int flag=true;
	      for(int j=2;j<=sqrt(i);j++)
	      {
	        if(i%j==0)
	       { 
	         flag=false;
	         break;
	       }
	      }
	      if(flag==true)
	        cnt++;
   }
	  cout<<cnt<<"\n";
	}

	return 0;
}


#include <stdio.h>
#include <string.h>
#define min(a,b) (((a)<(b)) ? (a):(b))
#define max(a,b) (((a)>(b)) ? (a):(b))





int main() {

  char n1[500];
  char n2[500];
  int temp1[500]={0,};
  int temp2[500]={0,};
  int temp3[500]={0,};
  scanf("%s",n1);
  scanf("%s",n2);
  
  
  for(int i=0;i<strlen(n1);i++)
  {
    temp1[i]=n1[i]-'0';
  }
  
  for(int i=0;i<strlen(n2);i++)
  {
    temp2[i]=n2[i]-'0';
  }
  


   for(int i=0;i<strlen(n1)/2;i++)
  {
    int tmp=temp1[i];
    temp1[i]=temp1[strlen(n1)-1-i];
    temp1[strlen(n1)-1-i]=tmp;
  }
   for(int i=0;i<strlen(n2)/2;i++)
  {
    int tmp=temp2[i];
    temp2[i]=temp2[strlen(n2)-1-i];
    temp2[strlen(n2)-1-i]=tmp;
  }
  
   ////
  // for(int i=0;i<strlen(n1);i++)
  // {
  //   printf("%d",temp1[i]);
  // }
  // printf("\n");

  // for(int i=0;i<strlen(n2);i++)
  // {
  //   printf("%d",temp2[i]);
  // }
  
  
  // printf("\n");

////
   
    for(int j=0;j<strlen(n2);j++)
    {
    
    
        for(int k=0;k<strlen(n1);k++)
        {     
                temp3[j+k] += temp2[j]*temp1[k];
          
        }
    }
  
  
  
  
    for(int i=0;i<500;i++)
    {
      if(temp3[i]>9)
      {
          temp3[i+1]+= temp3[i]/10;
      
        temp3[i]%=10;
      }
      
    }
    
    
  
    
    int idx=499;
    while(1)
    {
      if(temp3[idx]==0)
        {
          idx--;
        }
      if(temp3[idx]!=0)
        break;
    }
    
    for(int i=idx;i>=0;i--)
    {
      printf("%d",temp3[i]);
      
    }
  
  

  return 0;
}

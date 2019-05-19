#include <iostream>
#include <string.h>
using namespace std;



bool isPalindrome(char myString[],int start,int end)
{
  if(start==end)
    return true;
  else if (start+1==end)
  {
     if(myString[start]==myString[end])
      return true;
     else
      return false;
  }
  else
  {
    if (myString[start]==myString[end])
    {
      return isPalindrome(myString,start+1,end-1);
      
    }
    else
    {
      return false;
    }
    
  }
    
}



int main() {

  char myString[100];
  scanf("%s",myString);
  int len =strlen(myString);
  if( isPalindrome(myString,0,len-1))
    printf("YES");
  else
    printf("NO");
  return 0;
}

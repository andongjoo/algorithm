#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void unit2oct(unsigned int n)
{
   unsigned int mask=UINT_MAX;
   int i=0;
   for(i=32;i>0;i-=3)
   {
   		printf("%u",(n&(mask<<i-3)):0);
   	
   }printf("\n");
   
}

int main(int argc, char** argv) {

   unsigned int i;
   for(i=0;i<8;i++)
   {
      unit2oct(i);   
   }
   
   for(i=UINT_MAX;i>UINT_MAX-8;i--)
   {
      unit2oct(i);
   }
   
   return 0;
}

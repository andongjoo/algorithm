#include <stdio.h>

const int MAX=100;

struct queue{
  int f,r;
  int capacity;
  int data[MAX];
  int numElement=0;
  
  void create(int y)
  {
  f=0,r=0;
  capacity=y;
  // printf("capacity : %d\n",capacity);
  data[MAX]={0,};
 
  }
  
  void push()
  {
    int y;
    scanf("%d",&y);
    if (numElement>=capacity)
    {
      // printf("element : %d  capacity : %d\n",numElement,capacity);
      printf("Overflow\n");
    }
    else
      {
          data[r]=y;
          r=(r+1)%100;
          numElement++;
      }
  }
  void pop()
  {
    if(numElement<=0)
    {
      printf("Underflow\n");
    }
    else
    {
      data[f]=0;
      f = (f+1)%100;
      numElement--;
    }
  }
  int front()
  {
    if (numElement<=0)
    {

      return -1;
    }
    else
      {
        return data[f];
        
      }
  }
  
};


int main() {
  int n,m;
  scanf("%d %d",&n,&m);
  queue q;
  q.create(n);
  for(int i=0;i<m;i++)
  {
    int x;
    scanf("%d",&x);
    if (x==1)
    {
      q.push();
    }
    else if (x==2)
    {
      q.pop();
    }
    else if (x==3)
    {
      
     if (q.front()==-1)
     {
       printf("NULL\n");
     }
     else
     {
      printf("%d\n",q.front()) ;
     }
    }
  }
  return 0;
}

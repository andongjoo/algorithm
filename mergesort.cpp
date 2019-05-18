#include <iostream>

using namespace std;
const int MAX=100001;
int data[MAX];
int n;


void merge(int ls,int le,int rs,int re)
{
  int lp=ls;
  int rp=rs;
  int b[MAX];
  int temp=ls;
  while(lp<=le && rp<=re)
  {
    if (data[lp]>=data[rp])
    {
        b[temp++]=data[rp++];
      
    }
    else
      b[temp++]=data[lp++];
  }
  
  if(lp>le)
  {
    for(int i=rp;i<=re;i++)
    b[temp++]=data[i];
  }
  else
  {
    for(int i=lp;i<=le;i++)
      b[temp++]=data[i];
    
  }
  
  
 
  for(int i=ls;i<=re;i++)
    data[i]=b[i];
  
}

void mergeSort(int start,int end)
{
  if(start>=end)
  {
    return;
  }
  
  int mid=(start+end)/2;
  mergeSort(start,mid);
  mergeSort(mid+1,end);
  merge(start,mid,mid+1,end);
  
  
  
}


int main() {
 
 cin>>n;
 for(int i=0;i<n;i++)
  cin >>data[i];
  
  mergeSort(0,n-1);
  for(int i=0;i<n;i++)
    printf("%d ",data[i]);
  return 0;
}

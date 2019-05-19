#include <iostream>
#include <algorithm>
using namespace std;
int binary(int arr[],int s,int e,int value)
{
  if(s>e)
  {
    return 0;
  }
  
  else if (s==e)
  {
    if(arr[s]==value)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  
  else {
  int mid = (s+e)/2;
  
  if (arr[mid]==value)
  {
    return 1;
  }
  else if (arr[mid]<value)
  {
    return binary(arr,mid+1,e,value);
  }
  else
  {
    return binary(arr,s,mid-1,value);
  }
  }
}

int main() {

  int n;
  scanf("%d",&n);
  int a[3000001]={0,};
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  sort(a,a+n);  
  int m;
  scanf("%d",&m);
  for(int i=0;i<m;i++)
  {
    int x;
    scanf("%d",&x);
    int flag=binary(a,0,n-1,x);
    printf("%d\n",flag);
  }
  
  return 0;
}

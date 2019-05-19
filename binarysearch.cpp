#include <stdio.h>

int binarysearch(int arr[],int s,int e,int value)
{
  if (s>e)
  {
    return -1;
  }
  
  else if (s==e)
  {
    if (value==arr[s])
      return s;
    else 
      return -1;
  }
  
  else {
    
    int mid =(s+e)/2;
    if (arr[mid]==value)
    {
      return mid;
    }
    else if (arr[mid]<value)
    {
      return binarysearch(arr,mid+1,e,value);
    }
    else 
    {
      return binarysearch(arr,s,mid-1,value);
    }
  }
}

int main() {
  int n,q;
  scanf("%d %d ",&n,&q);
  
  int arr[100001];
  
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  
  for(int i=0;i<q;i++)
  {
  int m;
  scanf("%d",&m);
  int inx=binarysearch(arr,0,n-1,m);
  if( inx==-1)
  {
    printf("NO\n");
  }
  else
  {
    printf("YES\n");
  }
  
  }
  return 0;
}

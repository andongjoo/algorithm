/*
중복없는구간
이전다음
문제
n개의 숫자가 주어지고, 이 중에서 r개의 연속된 숫자를 선택했을 때, 이 연속 부분 내에는 숫자가 중복되지 않기를 원한다. 예를 들어, 다음과 같이 10개의 숫자에서 3개의 연속된 숫자를 선택할 수 있다.

중복없는구간

이렇게 선택을 하면, 선택된 숫자들 사이에서는 중복이 존재하지 않는다. r의 최댓값을 구하는 프로그램을 작성하시오. 위의 경우, (4, 2, 1, 3)을 선택하면 되므로 r의 최댓값은 4이다. r이 5 이상이 될 경우, 중복 없이 연속 부분을 선택하는 것이 불가능하다.

 

입력
첫째 줄에는 숫자의 개수 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 둘째 줄에 n개의 숫자가 주어진다. 각 숫자는 항상 1보다 크거나 같고, n보다 작거나 같다.  

출력
r의 최댓값을 출력한다.

 

예제 입력
10
1 3 1 2 4 2 1 3 2 1
예제 출력
4
 

예제 입력
7
7 1 4 2 5 3 6
예제 출력
7
*/
#include <iostream>
#include <algorithm>
int n;
int a[1000051]={0,};
int flag=2;

bool check(int interval)
{
  
  int checkdigit[100051];
  // printf("interval:%d\n",interval);
 for(int i=0;i<=n-interval;i++)
  {
    // printf("i:%d\n",i);
    int cnt=0;
    flag++;    
    for(int k=i;k<i+interval;k++)
    {
    
      if(checkdigit[a[k]]!=flag)
      {
          checkdigit[a[k]]=flag;
          ++cnt;
      }
      else
        break;
        
      // printf("k:%d a[%d]:%d cnt:%d\n",k,k,a[k],cnt);
      
		if (cnt>=interval)
  			 {
  	       // printf("cnt:%d,interval:%d\n",cnt,interval);
  			   return true;
  			 }
    }
  
  }
  
  return false;
}


using namespace std;
int main() {

  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  
  int s=1;
  int e=n;
  int r=0;;
  
  if (n==1)
  {
  	printf("1");
  	return 0;
  }
  
  
  int c=0;
  while(s<=e)
  {
    int mid = (s+e)/2;
    c++;
    // printf("s:%d e:%d mid:%d\n",s,e,mid);
    if (check(mid)==true )
    {
      if ( mid>r)
        r=mid;
      s=mid+1;
    }
	  else
      e=mid-1;
  	
  
  } 
  
  
  
  printf("%d\n",r);
 
	return 0;
}

/*
이전다음
문제
임의의 자연수는 그보다 작은 자연수들의 합으로 표현될 수 있다. 예를 들어 4의 경우,

4 = 3+1
  = 2+2 
  = 2+1+1 
  = 1+1+1+1
위와 같은 방법으로 표현 될 수 있다. 이 때 , 숫자의 구성이 같으면서 그 순서만이 다른 경우는 같은 경우로 생각하는데, 예를 들어 다음 세 가지 경우는 모두 같은 경우이다.

2 + 1 + 1, 1 + 2 + 1 , 1 + 1 + 2
자연수 n을 입력 받아 이를 n보다 작은 자연수들의 합으로 나타내는 방법을 모두 출력하는 프로그램을 재귀 호출을 사용하여 작성하시오.

 

입력
첫 줄에 2 이상 20 이하의 자연수 n이 주어진다.

 

출력
첫째 줄부터 모든 방법을 한 줄에 하나씩 출력한다. 하나의 식 안에는 큰 숫자가 앞으로 오도록 하고, 전체적으로는 앞의 숫자가 큰 식이 먼저 출력되도록 한다. 숫자와 더하기 사이에는 공백이 없다. 그리고 마지막 줄에는 나누어진 자연수의 개수를 출력한다.

 

예제 입력
5
예제 출력
4+1
3+2
3+1+1
2+2+1
2+1+1+1
1+1+1+1+1
6
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100]={0,};
int cnt=0;
void division(int rest,int index)
{
  if (rest<=0)
  {
   if (rest==0)
      {
      bool big=true;
      for(int i=0;i<index;i++)
      {
        if ( a[i]<a[i+1])
          big=false;
      }
      
      //printf
      if (big ==true)
      {
        cnt++;
      printf("%d",a[0]);
      for(int i=1;i<index;i++)
      {
        printf("+%d",a[i]);
      }
      printf("\n");
      //
      }  
        
        
      }  
    return;
  }
  
  
  for(int i=n-1;i>0;i--)
  {
     a[index]=i;
     division(rest-i,index+1);
  }

}



int main() {
  
  cin >>n;
  division(n,0);
  printf("%d",cnt);
  return 0;
}

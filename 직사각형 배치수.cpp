/*
이전다음
문제
2 x N 직사각형 모양의 칸이 있다. 이를 2 x 1 모양의 타일로 가득 채우려 한다. 가능한 경우의 수를 출력하는 프로그램을 작성하시오. 단, 가능한 경우의 수가 매우 많을 수 있으므로, 그 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.

예를 들어, N = 3 일 경우에는 다음 세 가지의 가능한 경우가 존재한다.

alt text

 

입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100 )  

출력
가능한 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.

 

예제 입력
3
예제 출력
3
 

예제 입력
8
예제 출력
34
 

예제 입력
37
예제 출력
87896
*/

#include <iostream>
using namespace std;
const int MAX =101;
const int MOD=1000007;
int dp[MAX]={0,};
int n;


int go(int n)
{
  if(n==1)
    return 1;
  else if (n==2)
    return 2;
  else if (dp[n]!=0)
        return dp[n]%MOD;
  else
    {dp[n]=(go(n-1)+go(n-2));
    return dp[n]%MOD;
    }
}


int main() {


  cin>>n;

  dp[1]=1;
  dp[2]=2;
  int result=go(n);
  
  printf("%d\n",result);
  
  // for(int i=1;i<=n;i++)
  //   printf("%d ",dp[i]);
  
  
  
  return 0;
}

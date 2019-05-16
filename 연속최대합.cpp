/*
N개의 정수가 주어질 때, 연속된 부분을 선택하여 합을 최대화 하는 프로그램을 작성하시오. 예를 들어, 아래와 같이 8개의 숫자가 있을 경우, 색칠된 부분을 선택했을 때 그 합이 가장 최대가 된다.

연속부분최대합

 

입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 1,000,000 ) 두 번째 줄에 n개의 정수가 주어진다.  

출력
연속된 부분을 선택하였을 때의 최댓값을 출력한다.

 

예제 입력
8
2 3 -5 8 -3 4 2 -9
예제 출력
11
 

예제 입력
5
-1 -2 3 -2 4
예제 출력
5
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=1000001;
int n;
int dp[MAX];
int a[MAX];

int main() {
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];    
  }
  dp[0]=a[0];
  
  for(int i=1;i<n;i++)
  {
    dp[i]= max( dp[i-1]+a[i],a[i]);  
  }
  
  int result=-99999999;
  for(int i=0;i<n;i++)
  {
    if (result<dp[i])
      result=dp[i];
  }
  printf("%d",result);

  return 0;
}

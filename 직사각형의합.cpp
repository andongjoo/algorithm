/*
직사각형의합
이전다음
문제
N x M 의 직사각형이 주어지며, 각 칸에는 정수가 들어있다. 이제 Q개의 질문에 대하여 답을 해야 하며, 각각의 질문은 (a, b)부터 (c, d)까지의 직사각형에 들어있는 정수의 합을 묻는다. 예를 들어, 다음과 같이 5 x 5 의 직사각형이 주어질 때, (1, 2) 부터 (3, 3) 까지의 직사각형에 들어있는 정수의 합은 26 이다.

alt text

 

입력
첫 번째 줄에 N, M, Q가 주어진다. ( 1 ≤ N, M ≤ 1,000, 1 ≤ Q ≤ 1,000,000 ) 두 번째 줄부터 N x M 직사각형이 주어진다. 직사각형 안의 숫자 S는 -100이상 100이하이다. 그 후 Q개의 질문이 주어진다. 각각의 질문은 “a b c d” 로 이루어 져 있으며, 이는 (a, b) 부터 (c, d) 까지의 직사각형에 들어있는 정수의 합을 묻는다. (0 ≤ a ≤ c < N, 0 ≤ b ≤ d < M)  

출력
각 질문에 대한 답을 출력한다.

 

예제 입력
5 5 3
 1 -2 3 2 8
-8 -9 3 4 5
 2 4 7 8 2
 1 4 3 1 4
-1 2 5 -6 3
1 2 3 4
0 0 1 1
2 0 2 1
예제 출력
37
-18
6
*/

#include <iostream>
using namespace std;
const int MAX=1001;
int arr[MAX][MAX];
int dp[MAX][MAX];
int main() {

  int n,m,q;
  cin>>n>>m>>q;

  for(int i=0;i<n;i++)
  {for(int j=0;j<m;j++)
    {  cin>>arr[i][j];
      dp[i][j]=arr[i][j];
    }
  }
  
  
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      dp[i][j]+=dp[i-1][j];
      
      
    }
    
    
  }
  
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<m;j++)
  //   {
  //     printf("%d ",dp[i][j]);
      
  //   }
  //   printf("\n");
    
  // }
  
  int a,b,c,d;
  for(int i=0;i<q;i++)
  {
    cin>>a>>b>>c>>d;
    int sum=0;
  if(a>=1)  
  {  for(int i=b;i<=d;i++)
    {
      sum+=dp[c][i];
      sum-=dp[a-1][i];
    }
  }
  else
  {
    for(int i=b;i<=d;i++)
    {
      sum+=dp[c][i];
     
    }
  }
  printf("%d\n",sum); 
  }
  
  
  return 0;
}

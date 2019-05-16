/*
팰린드롬이란, 앞으로 읽으나 뒤로 읽으나 똑같은 문자열을 말한다. 예를 들어, “abcba”, “abccba” 등이 있을 수 있다. 문자열이 주어질 때, 이를 팰린드롬으로 만들기 위하여 추가해야 하는 최소의 문자 개수를 출력하는 프로그램을 작성하시오. 예를 들어, 문자열이 “abca” 로 주어질 경우, ‘b’만 추가하면 “abcba” 를 만들 수 있으므로, 이 때는 1개의 문자만 추가하면 된다. 또 다른 예로써, 문자열이 “adcba” 로 주어질 경우에는, 문자 2개를 추가해야 한다.

 

입력
첫 번째 줄에 문자열이 주어진다. 이 문자열의 길이는 1,000 을 넘지 않는다.  

출력
주어진 문자열을 팰린드롬으로 만들기 위해서 추가해야 하는 문자 개수의 최솟값을 출력한다.

 

예제 입력
adcba
예제 출력
2
 

예제 입력
abccbdbac
예제 출력
3
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=1001;
int dp[MAX][MAX]={0,};
char str1[MAX];
char str2[MAX];

int main() {
  scanf("%s",str1);
  scanf("%s",str2);

  int len1=strlen(str1);
  int len2=strlen(str2);
  
  if(str1[0]==str2[0])
    dp[0][0]=0;
  else
    dp[0][0]=1;
    
  for(int i=0;i<len1;i++)
  {
    if (str2[0]==str1[i+1])
    { 
      dp[0][i+1]= dp[0][i];
        
        for(int j=i+1;j<len1;j++)
        {  dp[0][j+1]=dp[0][j]+1;
      
        }
        break;
    }
    else
      dp[0][i+1]=dp[0][i]+1;
    
  }
  
  for(int i=0;i<len1;i++)
    printf("%d ",dp[0][i]);
  printf("\n");


  for(int i=0;i<len2;i++)
  {
    if (str1[0]==str2[i+1])
    {  dp[i+1][0]= dp[i][0];
        
        for(int j=i+2;j<len2;j++)
        {  dp[j][0]=dp[j-1][0]+1;
      
        }
        break;
    }
    else
      dp[i+1][0]=dp[i][0]+1;
    
  }
  
  for(int i=1;i<len2;i++)
    printf("%d\n",dp[i][0]);
  printf("\n");  printf("\n");
  
  
    for(int j=1;j<len2;j++)
  {
    
    for(int i=1;i<len1;i++)
    {
      if ( str1[i]==str2[j])
        dp[i][j]=dp[i-1][j-1];
      else
        dp[i][j]= min(dp[i-1][j]+1,dp[i][j-1]+1);
    }
    
  }
  
  for(int i=0;i<len2;i++)
  {
    
    for(int j=0;j<len1;j++)
    {
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }
  
  printf("%d",dp[len1-1][len2-1]);
  return 0;
}

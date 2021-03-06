/*
거듭제곱구하기L
이전다음
문제
n과 m이 주어질 때, n의 m승을 구하는 프로그램을 작성하시오. 단, n의 m승의 값이 커질 수 있기 때문에, 정답을 10,007 으로 나눈 나머지를 출력한다.

 

입력
첫 번째 줄에 숫자 n과 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000,000,000,000,000,000 )  

출력
첫째 줄에 n의 m승을 10,007 으로 나눈 나머지를 출력한다.

 

예제 입력
3 4
예제 출력
81
 */
 
 #include <iostream>
using namespace std;

long long int n,m;

long long int pow(long long int n,long long int m)
{
  if(m==1)
  {
    return n;
  }
  
  else
  {
    int mid=m/2;
    if (m%2==1)
    {
      return n*pow(n,m/2)*pow(n,m/2)%10007;
    
    }
    else
    {
      return pow(n,m/2)*pow(n,m/2)%10007;
      
    }
    
  }
}


int main() {
  cin>>n>>m;
  long long int x=pow(n,m);
  printf("%lld",x);
  
  return 0;
}

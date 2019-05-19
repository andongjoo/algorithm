/*combinationzero
이전다음
문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

nCm은 수식으로 n!/m!(n-m)! 으로 구할 수 있다. (5! = 1 * 2 * 3 * 4 * 5)

n과 m이 주어졌을때 nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에 정수 n, m(0≤m≤n≤1,000,000)이 들어온다.

 

출력
첫째 줄에 0의 개수를 출력한다.

 

예제 입력
25 12
예제 출력
2
*/#include <iostream>
#include <algorithm>
using namespace std;

int find2(int n)
{
	
	int cnt=0;

  if(n==0)
    return 0;

	for(int i=2;i<=n;i+=2)
	{
	  int k=i;
	  while(k%2==0)
	  {
	    cnt++;
	    k=k/2;
	  }
	  
	}

  	return cnt;
}

int find5(int n)
{
  
  int cnt=0;
  if(n==0)
    return 0;
  
  for(int i=5;i<=n;i+=5)
	{
	  int k=i;
	  while(k%5==0)
	  {
	    cnt++;
	    k=k/5;
	    
	  }
	  
	}


	return cnt;
	
}


int main() 
{
  
  int n,m;
  cin >> n>>m;

  int cnt2=find2(n);
  int cnt5=find5(n);
  int cntm2=find2(m);
  int cntm5=find5(m);
  int cntnm2=find2(n-m);
  int cntnm5=find5(n-m);
  int a=cnt2-cntm2-cntnm2;
  int b=cnt5-cntm5-cntnm5;
  
	int c=min(a,b);
  printf("%d",c);


	return 0;
}

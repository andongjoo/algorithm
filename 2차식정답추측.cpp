/*
2차식 정답 추측
이전다음
문제
2차식 f(x) = x*x+ x 가 있고, 숫자 a가 주어진다. 우리는 f(x) = a 를 만족하는 x의 값을 찾고 싶지만, 보통 이 값은 정수로 떨어지지 않는 경우가 많다. 예를 들어, f(x) = 20 을 풀고자 한다면, x = 4이기 때문에 이는 정수이지만, f(x) = 103 을 풀고자 한다면 이는 x = 9.6612... 로써 정수가 아니다.

이 문제에서는 x의 정수부분이 얼마인지를 구하는 프로그램을 작성하시오. 예를 들어, f(x) = 103 을 풀고자 한다면, x = 9.6612... 이기 때문에 정수부분은 9가 된다.

 

입력
첫 번째 줄에 숫자 a가 주어진다. ( 1 ≤ a ≤ 1,000,000,000,000,000,000 )  

출력
f(x) = a 를 만족하는 x의 정수부분을 출력한다.  

예제 입력
103
예제 출력
9*/
#include <iostream>
#include <math.h>
using namespace std;

long long sum(long x)
{
	return x*x+x;
}

int main(int argc, char** argv) {


	long long   a;
	cin>>a;
	
	long long  int start=0;
	long long  int end=sqrt(a) ;
		
  if (a==1)
  {
    printf("0");
    return 0;
  }
	
	if (sum(end)<=a && sum(end+1))
		{
			printf("%lld\n",end);
			return 0;
		}
		
		long long int s = start;
		long long int e = end;	
	
	
	while(s+1<e)
	{
	
		if ( s>e)
			return 0;
		
		long long int mid = (s+e)/2;
		if (sum(mid) <= a && sum(mid+1)>a)
		{
			printf("%lld\n",mid);
			return 0;
		}
		
		if ( sum(mid)<a)
		{
			s = mid;
		}
		else if (sum(mid)>a)
		{
			e=mid;
		}
		
	}


	return 0;
}

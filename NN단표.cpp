/*
이전다음
문제
 구구단표처럼 NN단표를 만들었다고 한다.

NN단표는 2차원 배열의 모양으로 곱셈 1단부터 N단까지의 값들을 적어놓은 형태이다.

NN단표의 배열을 A라고 했을 때, 배열의 들어가는 수 A[i][j]=i*j이다.(즉, 4행 7열에는 28, 7행 5열에는 35가 들어가 있다.)

알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.

이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.  

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다. K는 N*N보다 작거나 같은 자연수이다.  

출력
K번째 원소를 출력한다.

 

예제 입력
3
7
예제 출력
6

*/
#include <iostream>
#include <math.h>
#include <algorithm>
int n;
int k;
int a[100][100]={0,};
long long int count(long long int mid)
{ 
  
    long long int cnt=0;
    for(int i=1;i<=n;i++)
    {
      if(n<(mid/i))
       { 
         cnt+=n;
       }
      else
      {
        cnt+= (mid/i);
      }
      // printf("cnt:%d\n",cnt);
      
    }
    return cnt;
}

using namespace std;
long long int num=100000000001;

int main() {
  cin >> n>>k;
  
  int s=1;
  int e=n*n;
  int mid;
  while(s<=e)
  {
    int mid=(s+e)/2;
    
    long long int c=count(mid);
    // printf("mid:%d cnt:%d\n",mid,c);
    
    
    
    
    if ( c>=k )
      {
        
        e=mid-1;
       if(num>mid)
       {
         num=mid;
       }
       
      }
    else if (c<k)
     {
      
       
       s=mid+1;
     }
  } 
  printf("%d",num);
  
  
  
  
	return 0;
}

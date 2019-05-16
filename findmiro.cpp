/*
문제
아래와 같이 이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 출력하는 프로그램을 작성하시오. 아래 그림에 대하여 S에서 E까지 가는 최단거리는 22이다.

ec-16

 

입력
첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다.

 

출력
(N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다.

 

예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 0 1 0
0 1 1 1 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 1 1 1 1 0 0 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 1 0 0



예제 출력
22
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1003;

int n,m;
int cnt=0;
vector<int> g[MAX];
queue <int> q;
bool check[MAX][MAX];
int c[MAX][MAX]={0,};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs()
{
  check[n-1][0]=true;
  
  q.push(n-1);
  q.push(0);
  c[n-1][0]=0;
  
  while(!q.empty())
  {
    
    int l,r;
    l=q.front();
    q.pop();
    r=q.front();
    q.pop();
    
    // printf("%d,%d\n",l,m);
    
    for(int i=0;i<4;i++)
    {
      if (check[l+dy[i]][r+dx[i]]==false &&  0<=(l+dy[i]) &&(l+dy[i])<n  &&  0<=  (r+dx[i]) && (r+dx[i])<m &&g[l+dy[i]][r+dx[i]]!=1   )
      {
          q.push(l+dy[i]);
          q.push(r+dx[i]);
          check[l+dy[i]][r+dx[i]]=true;
          c[l+dy[i]][r+dx[i]]=c[l][r]+1;   
          // printf("(%d,%d) %d \n",l+dy[i],m+dx[i],cnt);   
      }
      
    }
    
    
  } 
  
  
}


int main() {

 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<m;j++)
   {
      int a;
      cin>>a;
      g[i].push_back(a);
     
   }
   
 }



  bfs();
  
// for(int i=0;i<n;i++)
// {
//   for(int j=0;j<m;j++)
//   {
//     printf("%2d ",c[i][j]);
    
//   }
//   printf("\n");
// }
  printf("%d",c[0][m-1]);

  return 0;
}

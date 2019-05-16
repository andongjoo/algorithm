/*
그래프와 출발점, 도착점이 주어질 때 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 예를 들어, 아래 그림에서 출발 정점이 0, 도착 정점이 10이라고 할 때, 최단거리는 3이다.

ec-21

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 1,000,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. M+1 번째 줄에 대하여 출발점과 도착점의 정점 번호가 주어진다.

 

출력
출발점에서 도착점까지 이동하기 위한 최단거리를 출력한다.

 

예제 입력
11 14
0 1
0 2
1 2
1 4
1 5
2 3
3 7
4 7
4 9
4 10
5 6
6 8
6 10
7 8
0 10




예제 출력
3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX =10001;

vector <int> g[MAX];
int table[MAX];


int n,m;
int startnode,endnode;
int cnt[MAX]={0,};
bool check[MAX];

  
int main() {
  cin>>n>>m;
  
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    
    g[a].push_back(b);
    g[b].push_back(a);
    
  }
  cin>>startnode>>endnode;
  
  queue<int> q;
  
  
  q.push(startnode);
  check[startnode]=true;
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    for(int i=0; i<g[current].size();i++)
    {
      int next=g[current][i];
      if ( check[next]==false)
      {
        q.push(next);
        check[next]=true;
        cnt[next]=cnt[current]+1;
      }
    }
  }
  
  
  printf("%d",cnt[endnode]);
  
  
 
    
  return 0;
}

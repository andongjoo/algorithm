/*
정점의 번호가 1부터 N까지 존재하는 그래프 G가 존재하고, 어떠한 정점 집합 S={i, j, k,..} 끼리는 서로 간선으로 연결되어있으며, 그 이외의 정점 집합(S`)과는 연결되어있지 않을때, 집합 S로 그려지는 그래프를 그래프 G의 연결요소(Connected Component)라고 합니다. 만약 정점 집합 S와 S`의 합집합이 G의 정점의 전체일 경우, 그래프 G의 연결요소의 개수는 2개입니다. 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

 

입력
첫째 줄에 정점의 개수 V과 간선의 개수 E이 주어진다. (1 ≤ V ≤ 1,000, 0 ≤ E ≤ V×(N-1)/2) 둘째 줄부터 E개의 줄에 간선의 양 끝점 v1와 v2가 주어진다. (1 ≤ v1, v2 ≤ N, v1 ≠ v2) 같은 간선은 한 번만 주어진다.

 

출력
첫째 줄에 연결 요소의 개수를 출력한다.

 

예제 입력 1
5 4
1 2
3 4
3 5
4 5
예제 출력 1
2
 

예제 입력 2
5 6
1 2
1 5
2 4
3 4
3 5
4 5
예제 출력 2
1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX =1001;

bool check[MAX];
bool check2[MAX];
vector<int> g[MAX];

int v,e;
int t[MAX]={0,},clk=0;
int order[MAX]={0,},order_len=0;
int group_cnt=0,group[MAX]={0,};

void dfs(int node)
{
  check[node]=true;
  
  for(int i=0;i<g[node].size();i++)
  {
    int next_node=g[node][i];
    if(check[next_node]==false)
      dfs(next_node);
  }
  
  t[node]=++clk;
  order[++order_len]=node;
  
}

void get_my_group(int node)
{
  check2[node]=true;
  
  group[group_cnt]=node;
  for(int i=0;i<g[node].size();i++)
  {
      int next_node=g[node][i];
      if(check2[next_node]==false)
        get_my_group(next_node);
  }
  
}


int main() {
  cin>>v>>e;
  
  for(int i=0;i<e;i++)
  {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  
  for(int i=1;i<=v;i++)
  {
    if ( check[i]==false)
      dfs(i);
  }
 
  // for(int i=1;i<=v;i++)
  //   printf("%d ",t[i]);
  // printf("\n");
  // for(int i=1;i<=v;i++)
  //   printf("%d ",order[i]);
  // printf("\n");
  
  for(int i=order_len;i>=1;i--)
  {
    if (check2[order[i]]==false)
    {  get_my_group(order[i]);
        group_cnt++;
    } 
  }
  
  printf("%d ",group_cnt);
  return 0;
}


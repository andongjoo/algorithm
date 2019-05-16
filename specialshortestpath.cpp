/*
특정 최단거리
이전다음
문제
무방향 그래프가 주어질 때, 정점 1번에서 정점 N번으로 가는 최단거리를 구하려 하는데, 그 과정에서 두 개의 정점을 반드시 거쳐야 한다. 한 번 방문했던 정점을 또 다시 방문하는 것도 허용하고, 간선도 마찬가지로 여러번 방문하는 것을 허용한다고 할 때, 1번에서 N번으로 가는 “특정한" 최단거리를 출력하는 프로그램을 작성하시오.

 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a와 정점 b가 가중치 c인 간선으로 연결되어 있다는 의미이다. 마지막 줄에는 반드시 거쳐야 하는 두 정점 A, B가 주어진다. ( 1 ≤ a, b, A, B ≤ 1,000, 1 ≤ c ≤ 50,000 )

 

출력
1번 정점에서 N번 정점으로 가는 “특정한" 최단거리를 출력한다. 단, “특정한" 최단거리란, 주어진 정점 A와 B를 반드시 방문할 때의 최단거리를 의미한다.

 

예제 입력
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3



예제 출력
7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX =1101;
vector <int> g[MAX];
vector <int> cost[MAX];

int table[MAX];
bool check[MAX];

int table2[MAX];
bool check2[MAX];

int table3[MAX];
bool check3[MAX];

int n,m,x,y;
  
int main() {

  cin>>n>>m;
  
  
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    
    g[a].push_back(b);
    g[b].push_back(a);
    cost[a].push_back(c);
    cost[b].push_back(c);
  }
  cin>>x>>y;

  
  for(int i=1;i<=n;i++)
    table[i]=987987987;
    
  table[1]=0;
 
  for(int i=1;i<=n;i++)
  {
      int minvalue=987987987;
      int minindex=-1;
      
      for(int j=1;j<=n;j++)
      {
        
        if(check[j]==false && minvalue>table[j])
      {    minvalue=table[j];
          minindex=j;
        
      } 
      
      }
      check[minindex]=true;
      
      for(int j=0;j<g[minindex].size();j++)
      {
        int node2=g[minindex][j];
        int cost2=cost[minindex][j];
      
        if(table[node2] > table[minindex]+cost2)
          table[node2]=table[minindex]+cost2;
        
      }
    
  }
  
  
  
  for(int i=1;i<=n;i++)
    table2[i]=987987987;
    
  table2[x]=0;
 
  for(int i=1;i<=n;i++)
  {
      int minvalue=987987987;
      int minindex=-1;
      
      for(int j=1;j<=n;j++)
      {
        
        if(check2[j]==false && minvalue>table2[j])
      {    minvalue=table2[j];
          minindex=j;
        
      } 
      
      }
      check2[minindex]=true;
      
      for(int j=0;j<g[minindex].size();j++)
      {
        int node2=g[minindex][j];
        int cost2=cost[minindex][j];
      
        if(table2[node2] > table2[minindex]+cost2)
          table2[node2]=table2[minindex]+cost2;
        
      }
    
  }
  
 
  
  
  for(int i=1;i<=n;i++)
    table3[i]=987987987;
  
  table3[y]=0;
  
  for(int i=1;i<=n;i++)
  {
    int minindex=-1;
    int minvalue=987987987;
    
    for(int j=1;j<=n;j++)
    {
      if(check3[j]==false && table3[j]<minvalue)
        {
          minvalue=table3[j];
          minindex=j;
        }
      
    }
      check3[minindex]=true;
    
    for(int j=0;j<g[minindex].size();j++)
    {
         int node2=g[minindex][j];
         int cost2=cost[minindex][j];
      
        if(table3[node2] >table3[minindex]+cost2)
              table3[node2]=table3[minindex]+cost2;
      
    }
    
    
    
    
    
  }
  
  
  
  // printf("result1 : %d %d %d\n",table[x],table2[y],table3[n]);
  int result1=table[x]+table2[y]+table3[n];
  
  
  
  
  for(int i=0;i<=n;i++)
    check2[i]=false;
    
  for(int i=1;i<=n;i++)
    table2[i]=987987987;
    
  table2[y]=0;
 
  for(int i=1;i<=n;i++)
  {
      int minvalue=987987987;
      int minindex=-1;
      
      for(int j=1;j<=n;j++)
      {
        
        if(check2[j]==false && minvalue>table2[j])
      {    minvalue=table2[j];
          minindex=j;
        
      } 
      
      }
      check2[minindex]=true;
      
      for(int j=0;j<g[minindex].size();j++)
      {
        int node2=g[minindex][j];
        int cost2=cost[minindex][j];
      
        if(table2[node2] > table2[minindex]+cost2)
          table2[node2]=table2[minindex]+cost2;
        
      }
    
  }
  
  
  
  
  for(int i=0;i<=n;i++)
    check3[i]=false;
  
    for(int i=1;i<=n;i++)
    table3[i]=987987987;
  
  table3[x]=0;
  
  for(int i=1;i<=n;i++)
  {
    int minindex=-1;
    int minvalue=987987987;
    
    for(int j=1;j<=n;j++)
    {
      if(check3[j]==false && table3[j]<minvalue)
        {
          minvalue=table3[j];
          minindex=j;
        }
      
    }
      check3[minindex]=true;
    
    for(int j=0;j<g[minindex].size();j++)
    {
        int node2=g[minindex][j];
        int cost2=cost[minindex][j];
      
        if(table3[node2] >table3[minindex]+cost2)
              table3[node2]=table3[minindex]+cost2;
      
    }
    
    
    
    
    
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  // printf("result2 : %d %d %d\n",table[y],table2[x],table3[n]);
  
  
  int result2 = table[y]+table2[x]+table3[n];
  int result3= table[n]+table2[]
  printf("%d\n",min(result2,result1));
    
    // for(int i=1;i<=n;i++)
    //   printf("%d ",table[i]);
    //   printf("\n");
    //   for(int i=1;i<=n;i++)
    //   printf("%d ",table2[i]);
    //   printf("\n");
    //   for(int i=1;i<=n;i++)
    //   printf("%d ",table3[i]);
    //   printf("\n");
      
  return 0;
}

#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
const int MAX =1001;
int n,m;
vector <int> g[MAX];
vector <int> g2[MAX];
bool check[MAX];
bool check2[MAX]; 
   

void dfs(int node)
{
  printf("%d ",node);
  check[node]=true;
  for(int i=0;i<g[node].size();i++)
  {
    int next=g[node][i];
    
    if(check[next]==false)
      dfs(next);
    
  }
  
  
}

void bfs()
{
 queue <int> q;
 q.push(0);
 check2[0]=true;
 while(!q.empty())
 {
   
   int current=q.front();
   printf("%d ",current);
   q.pop();
   for(int i=0;i<g2[current].size();i++)
   {
     int next=g2[current][i];
     if(check2[next]==false)
     {
       q.push(next);
       check2[next]=true;
     }
     
   }
   
   
 }
 
  
}



int main()
{
  
  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;

   g[a].push_back(b);
   g[b].push_back(a);
   g2[a].push_back(b);
   g2[b].push_back(a);
   
  }
 
  for(int i=0;i<MAX;i++)
  {
    sort(g[i].begin(),g[i].end());
    
    sort(g2[i].begin(),g2[i].end());
  }
  
  dfs(0);
  printf("\n");
  bfs();
  
}

#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;
const int MAX =1001;
int n,m;
vector <int> g[MAX];
bool check[MAX];
   

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

int main()
{
  
  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;

   g[a].push_back(b);
   g[b].push_back(a);
  }
 
  for(int i=0;i<MAX;i++)
  {
    sort(g[i].begin(),g[i].end());
    
  }
  
  dfs(0);
  printf("\n");
}

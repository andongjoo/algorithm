#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;

int n,m;

vector<int> g[MAX];
queue <int> q;
bool check[MAX];
int cnt=0;
void bfs()
{
 
  q.push(1);  
  check[1]=true;
  
  while(!q.empty())
  {
    int current=q.front();
    q.pop();
    // printf("%d ",current);

          
    for(int i=0;i<g[current].size();i++)
    {
      int next=g[current][i];
      if(check[next]==false)
      {
        q.push(next);
        check[next]=true;
      
        cnt++;
      }
   
    }
    
  }
  
  
  
}


int main() {

  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    
  }
  
  
  bfs();
 
  printf("%d",cnt);
  

  return 0;
}

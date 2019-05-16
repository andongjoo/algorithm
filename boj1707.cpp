#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;

int n,m;
int flag=0;
vector<int> g[MAX];
queue <int> q;
bool check[MAX];
int color[MAX];
void bfs()
{
  int c=1;
  q.push(1);  
  check[1]=true;
  color[1]=c;
  
  
  while(!q.empty())
  {
    int current=q.front();
    q.pop();
    // printf("%d ",current);
    
    if(color[current]==1)
        c=2;
    else
        c=1;
          
    for(int i=0;i<g[current].size();i++)
    {
      int next=g[current][i];
      if(check[next]==false)
      {
        q.push(next);
        check[next]=true;
        color[next]=c;
        
        // printf("color[%d]:%d\n",next,color[next]);
        // if(color[next]==color[current])
        // {
        //   // printf("front %d color[%d] next:%d color[%] : %d\n",current,current,color[current],next,next,color[next]);
        //   flag=1;
        
          
        // }
        
        
      }
      else if (check[next]==true)
      {
        if(color[next]==color[current])
        { 
            // printf("front %d color[%d]:%d next:%d color[%d] : %d\n",current,current,color[current],next,next,color[next]);
          flag=1;
        
          
        }
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
 
  if(flag==1)
    printf("No");
  else
    printf("Yes");

  

  return 0;
}

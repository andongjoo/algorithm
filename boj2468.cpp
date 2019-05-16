#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=105;
int map[MAX][MAX]={0,};
int n;
bool check[MAX][MAX];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int cnt=0;
int safe=0;

void bfs(int a,int b,int h)
{
  queue<int> q;
  q.push(a);
  q.push(b);
  check[a][b]=true;

  
  while(!q.empty())
  {
    int yy=q.front(); q.pop();
    int xx=q.front(); q.pop();
    
      check[yy][xx]=true;
      
    for(int i=0;i<4;i++)
    {
      int y=dy[i]+yy;
      int x=dx[i]+xx;
      
      if( 0<=y && y<n && 0<=x && x<n && check[y][x]==false && map[y][x]>h)
      {
        q.push(y);
        q.push(x);
        // check[y][x]=true;
      
      }
      
    }
    
    
    
  }
  
  
  
}

int main() {
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>map[i][j];

  int maxh=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(maxh<map[i][j])
        maxh=map[i][j];
    }
  }
  

for(int k=1;k<maxh;k++)
      {
        cnt=0;
      for(int i=0;i<n;i++)
          {
        for(int j=0;j<n;j++)
          {
        
            if( map[i][j]>k && check[i][j]==false)
              { 
                bfs(i,j,k);
                cnt++;
              }
        
                }
              }
        if(cnt>safe)
              safe=cnt;
        
        for(int z=0;z<n;z++)
          for(int zz=0;zz<n;zz++)
              check[z][zz]=false;
  
      }

  printf("%d\n",safe);
  return 0;
}

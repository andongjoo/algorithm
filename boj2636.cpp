#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int cnt=0;
const int MAX =101;
int g[MAX][MAX]={0,};
bool check[MAX][MAX];
bool check2[MAX][MAX];
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int group[MAX];

void dfs(int y,int x)
{
  check2[y][x]=true;
  check[y][x]=true;
 
  for(int i=0;i<4;i++)
  {
    if ( 0<=y+dy[i]&& y+dy[i]<n && 0<=x+dx[i] && x+dx[i]<m && check[y+dy[i]][x+dx[i]]==false)
      {
        if(g[y+dy[i]][x+dx[i]]==1)
          { group[cnt]++;
            g[y+dy[i]][x+dx[i]]=0;
            check[y+dy[i]][x+dx[i]]=true;
          }
      }
  }
  
  for(int i=0;i<4;i++)
  {
    
    if ( 0<=y+dy[i] && y+dy[i]<n && 0<=x+dx[i] && x+dx[i]<m && check[y+dy[i]][x+dx[i]]==false)
      {
        if(g[y+dy[i]][x+dx[i]]==0)
          dfs(y+dy[i],x+dx[i]);
      }
    
  }
  
 
}

int main() {

  cin>>n>>m;
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>g[i][j];
    }
  }
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      
      
      if(g[i][j]==0 && check2[i][j]==false)
        {
          check2[i][j]=true;
          dfs(i,j);
          cnt++;
          // printf("%d %d\n",i,j);
          
        }
      
      for(int k=0;k<n;k++)
        for(int p=0;p<m;p++)
          check[k][p]=false;
      
    // for(int k=0;k<n;k++)
    //   {
    //   for(int p=0;p<m;p++)
    //   {printf("%d ",g[k][p]);
    //     }printf("\n");
    //   }printf("\n");
  
      
      
    }
  }
  printf("%d\n",cnt-1);
  
    printf("%d ",group[cnt-2]);
  
  return 0;
}

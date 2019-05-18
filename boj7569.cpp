

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=101;

int m,n,h;
int box[MAX][MAX][MAX]={0,};
bool check[MAX][MAX][MAX];
int dx[6]={0,0,-1,1,0,0};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,0,0,1,-1};
int cnt[MAX][MAX][MAX]={0,};
int flag=0;
  queue<int> q;
  
void bfs()
{
  
  while (!q.empty())
  {
    
    int z=q.front(); q.pop();
    int y=q.front();  q.pop();
    int x=q.front();  q.pop();
    check[z][y][x]=true;
        
    for(int i=0;i<6;i++)
    {
      if ( 0<=x+dx[i] && x+dx[i]<m && 0<=y+dy[i]&& y+dy[i]<n&& 0<=z+dz[i] && z+dz[i]<h && check[z+dz[i]][y+dy[i]][x+dx[i]]==false && box[z+dz[i]][y+dy[i]][x+dx[i]]==0)
      {
          q.push(z+dz[i]);
          q.push(y+dy[i]);
          q.push(x+dx[i]);
          box[z+dz[i]][y+dy[i]][x+dx[i]]=1;
          cnt[z+dz[i]][y+dy[i]][x+dx[i]]=cnt[z][y][x]+1;
          
      }
      
    }
    
    
    
    
  }
  
  
  
}

int main() {

  cin>>m>>n>>h;
  for(int k=0;k<h;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
    
          cin>>box[k][i][j];
      }
      
    }
  }
  
  
  for(int k=0;k<h;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
    
          if( box[k][i][j]==1 && check[k][i][j]==false)
              {
                flag=1;
                q.push(k);
                q.push(i);
                q.push(j);
              }
      } 
      
    }
  }
  bfs();
  
  
  // for(int k=0;k<h;k++)
  // {
  //   for(int i=0;i<n;i++)
  //   {
  //     for(int j=0;j<m;j++)
  //     {
    
  //         printf("%d ",cnt[k][i][j]);
  //     }printf("\n");
      
  //   }
  // }printf("\n");
  
  // for(int k=0;k<h;k++)
  // {
  //   for(int i=0;i<n;i++)
  //   {
  //     for(int j=0;j<m;j++)
  //     {
    
  //         printf("%d ",box[k][i][j]);
          
  //     }printf("\n");
      
  //   }
  // }
  
  for(int k=0;k<h;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
    
        if(box[k][i][j]==0)
        {
          // printf("여기다%d %d %d\n",k,i,j);
          // printf("%d\n",box[k][i][j]);
          printf("-1");
          return 0;
        }
        
      }
      
    }
  }
  
  int maxday=-1;
    for(int k=0;k<h;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
    
        if(cnt[k][i][j]>maxday)
        {
          maxday=cnt[k][i][j];
        }
        
      }
      
    }
  }
  
  if(flag==0)
   {
     printf("0");
   }
  else
    printf("%d",maxday);
  
  
  return 0;
}

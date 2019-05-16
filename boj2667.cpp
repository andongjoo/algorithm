#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=30;
char g[MAX][MAX]={0,};
bool check[MAX][MAX];
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int n;
int c=0;
int cc[3000]={0,};
queue <int> q;

int bfs(int y,int x)
{
  q.push(y);
  q.push(x);
  check[y][x]=true;
  int cnt=1;
  while(!q.empty())
  {
  
    int l,r;
    l=q.front();
    q.pop();
    r=q.front();
    q.pop();

    for(int i=0;i<4;i++)
    {
      
      if ( 0<=(l+dy[i]) && (l+dy[i])<n && 0<=(r+dx[i])  && (r+dx[i])<n && check[l+dy[i]][r+dx[i]]==false && g[l+dy[i]][r+dx[i]]==1    )
      {
          q.push(l+dy[i]);
          q.push(r+dx[i]);
          check[l+dy[i]][r+dx[i]]=true;
          cnt++;       
      }
      
      
    }
    
    
    
    
  }
    cc[c]=cnt;
}






int main() {

  cin>>n;
  for(int i=0;i<n;i++)
  {
    scanf("%s",g[i]);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
    g[i][j]-='0';
    }
   
  }
  
  
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     printf("%d ",g[i][j]);
  //   }
  //   printf("\n");
    
  // }
  
  
  for(int i=0;i<n;i++)
  {
    
    for(int j=0;j<n;j++)
    {
      
        if (g[i][j]==1 && check[i][j]==false)
        { 
          c++;
          bfs(i,j);
              
        }
    }
    
  }
  
  // printf("\n");
  
  printf("%d\n",c);
  sort(cc,cc+c+1);
  for(int i=1;i<=c;i++)
  {
    printf("%d\n",cc[i]);
  }


  return 0;
}

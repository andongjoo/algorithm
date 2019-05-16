#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=105;
int map[MAX][MAX]={0,};
int m,n,k;
bool check[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int num=0;
vector<int> area;

void bfs(int yy,int xx)
{
  int cnt=0;
  queue<int> q;
  q.push(yy);
  q.push(xx);
 check[yy][xx]=true;
  while(!q.empty())
  { 
    cnt++;
    int y=q.front();q.pop();
    int x=q.front();q.pop();
    // printf("%d %d / ",y,x);
      // check[y][x]=true;
    for(int z=0;z<4;z++)
    {
      int ny=y+dy[z];
      int nx=x+dx[z];
      if( 0<=ny && ny<m && 0<=nx && nx<n && check[ny][nx]==false && map[ny][nx]==0)
      {
          q.push(ny);
          q.push(nx);
          check[ny][nx]=true;
          
      }
    }
  }
  area.push_back(cnt);
// printf("\n"); 
}


int main() {
  cin>>m>>n>>k;
  
  for(int i=0;i<k;i++)
  {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
 
    for(int l=b;l<d;l++)
    {
    for(int j=a;j<c;j++)
      {
          map[l][j]=1;
      }
    }
    
  }
  
  // for(int i=0;i<m;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
      
  //     printf("%d ",map[i][j]);
  //   }printf("\n");
  // }printf("\n");
  
  
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(map[i][j]==0 && check[i][j]==false)
        {
          // printf("%d %d\n",i,j);
          num++;
         
          bfs(i,j);
         
         
        }
    }
  }

  printf("%d\n",num);
  sort(area.begin(),area.end());
  for(int i=0;i<num;i++)
    printf("%d ",area[i]);
  

  return 0;
}

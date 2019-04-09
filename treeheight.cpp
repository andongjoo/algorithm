#include <iostream>

using namespace std;
int g[1001][1001]={0,};
int visit[1001]={0,};
int cnt=0;

int n,r;
void dfs(int node,int val)
{
  
  val++;
  visit[node]=1;
  // printf("%d cnt:%d val:%d \n",node,cnt,val);
  if ( cnt<val)
    cnt=val;
 
  for(int i=0;i<100;i++)
  {
    if ( visit[i]==0 && g[node][i]==1)
    {
        
      dfs(i,val);
    }
      
  }
  

  return;  

}









int main() {
 
 
  cin>>n>>r;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    g[a][b]=1;
    g[b][a]=1;
  }
 
  dfs(r,0);
  printf("%d",cnt-1);
 
 
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1001;
vector<int> g[MAX];
vector<int> rg[MAX];
int check[MAX];
int check2[MAX];
int t[MAX],clk=1;
int order[MAX],order_len=0;
int group[MAX],group_cnt=1;


void get_my_group(int node)
{
    check2[node]=true;
    
    for(int i=0;i<rg[node].size();i++)
    {
      int node2=rg[node][i];
      if(!check2[node2])
      {
        get_my_group(node2);
      }
    
    }
    
    group[node]=group_cnt;
  
  
}

void get_time(int node)
{
  check[node]=true;
  
  for(int i=0;i<g[node].size();i++)
  {
    int node2=g[node][i];
    
    if(!check[node2])
    {
        get_time(node2);
    }
  }
  
  t[node]=clk++;
  order[order_len++]=node;
  
}








int n,m;

int main() {


  cin>>n>>m;
  
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    
    g[a].push_back(b);
    rg[b].push_back(a);
  }

  for(int i=1;i<=n;i++)
  {
    if(!check[i])
    {
      get_time(i);  
      
    }
      
    
  }


  for(int i=order_len-1;i>=0;i--)
  {
    int node = order[i];
    if(!check2[node])
    {
      get_my_group(node);
      group_cnt++;
    }
    
  }
  // for(int i=1;i<=n;i++)
  //   printf("%d ",order[i]);

  printf("%d",group_cnt-1);

  return 0;
}

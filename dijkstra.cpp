#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX =100;
vector <int> g[MAX];
vector <int> cost[MAX];

int table[MAX];
bool check[MAX];

int n,m,start,end2;
  
int main() {

  cin>>n>>m>>start>>end2;
  
  
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    
    g[a].push_back(b);
    g[b].push_back(a);
    cost[a].push_back(c);
    cost[b].push_back(c);
    
  }
  
  for(int i=0;i<n;i++)
    table[i]=987987987;
    
  table[start]=0;
 
  for(int i=0;i<n;i++)
  {
      int minvalue=987987987;
      int minindex=-1;
      
      for(int j=0;j<n;j++)
      {
        
        if(check[j]==false && minvalue>table[j])
      {    minvalue=table[j];
           minindex=j;
        
      } 
      
      }
      check[minindex]=true;
      
      for(int j=0;j<g[minindex].size();j++)
      {
        int node2=g[minindex][j];
        int cost2=cost[minindex][j];
      
        if(table[node2] > table[minindex]+cost2)
          table[node2]=table[minindex]+cost2;
        
      }
    
  }
  
  printf("%d\n",table[end2]);
  for(int i=0;i<n;i++)
    printf("%d ",table[i]);
    
  return 0;
}

/*
8 11 0 6
0 1 3
0 5 1 
1 2 4
1 3 1
1 5 1
2 4 6
2 6 9
2 7 4
3 4 2
4 6 9
6 7 3
*/
